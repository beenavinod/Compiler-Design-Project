%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	void yyerror(const char*);
	int yylex();

	extern FILE * yyin, *yyout;

	FILE *fp_icg, *fp_quad;
	
	extern int line;
	
	char buffer[100];
	int ln = 0, tempno = 0;

	int assignop = -1;		//assignment operator == += -=
	int unaryop = -1;		//unary operator type
	int exprno = -1;		//FOR loop , 3rd expression
	int m = 0;				//string length for buffer
	int literal = -1;       //literal or not
	int paramno = 0;		//Number of parameters

	char intbuf[20];
	char secIDbuf[20];



%}

%token  HASH INCLUDE STDIO STDLIB MATH STRING TIME IOSTREAM
%token  STRING_LITERAL HEADER_LITERAL PRINT RETURN
%left 	'+' '-'
%left 	'/' '*' '%'
%right 	'='
%right UMINUS


%union{	
	char sval[300];
}


%token 	<sval> INTEGER_LITERAL 
%token 	<sval> CHARACTER_LITERAL
%token 	<sval> FLOAT_LITERAL 
%token	<sval> IDENTIFIER  
%token 	<sval> FOR IF DO WHILE

%token	INC_OP 	DEC_OP 	LE_OP 	GE_OP 	EQ_OP 	NE_OP
%token	MUL_ASSIGN 	DIV_ASSIGN 	MOD_ASSIGN 	ADD_ASSIGN 	SUB_ASSIGN
%token	CHAR 	INT 	FLOAT 	VOID

%type <sval> 	additive_expression 
%type <sval>  	multiplicative_expression
%type <sval>	unary_expression
%type <sval>	relational_expression
%type <sval>	primary_expression
%type <sval> 	expression
%type <sval> 	postfix_expression
%type <sval>  	assignment_expression
%type <sval> 	conditional_expression
%type <sval>	equality_expression 
%type <sval>	unary_operator
%type <sval>	declarator


%start S

%%
S : program 
  	;

program
	: HASH INCLUDE '<' libraries '>' program
	| HASH INCLUDE HEADER_LITERAL 	 program
	| translation_unit
	;


translation_unit
	: ext_dec
	| translation_unit ext_dec
	;


ext_dec
	: declaration
	| function_definition	
	;


libraries
	: STDIO
	| STDLIB
	| MATH
	| STRING
	| TIME
	| IOSTREAM
	;


compound_statement
	: '{' '}' 
	| '{' block_item_list '}'
	;


block_item_list
	: block_item
	| block_item_list block_item 
	| error     { }

	;


block_item
	: declaration
	| statement
	| RETURN expression_statement	
	| function_call ';'
	| printstat ';'
	;


printstat
	: PRINT '(' STRING_LITERAL ')' 
	| PRINT '(' STRING_LITERAL ',' expression ')'
	;


declaration
	: type_specifier init_declarator_list ';' 
	;


statement
	: compound_statement 
	| expression_statement
	| iteration_statement
	| selection_statement
	;

selection_statement
	: IF '('expression ')'
		{
			fprintf(fp_icg, "ifFalse t%d goto L%d\n", --tempno, ln);
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;
		}
		statement
		{	
			fprintf(fp_icg, "L%d:\n", ln);
			fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
			ln++;
		}
	; 

iteration_statement
	: WHILE  {
		fprintf(fp_icg,"L%d:\n", ln);
		fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
		ln++;
		}
		'(' expression ')' {
			fprintf(fp_icg, "ifFalse t%d goto L%d\n", --tempno, ln);
			fprintf(fp_quad, "\tifFalse\t\tt%d\t\t  \t\tL%d\n", tempno, ln);
			tempno++;
		} 
		statement {
			fprintf(fp_icg, "goto L%d\n", --ln);
			fprintf(fp_quad, "\tgoto\t\t  \t\t  \t\tL%d\n", ln);
			ln++;

		fprintf(fp_icg,"L%d:\n", ln);
		fprintf(fp_quad, "\tLabel\t\t  \t\t  \t\tL%d\n", ln);
		ln++;
		
		}
	

	;



type_specifier
	: VOID 	
	| CHAR 	
	| INT 	
	| FLOAT 
	;


init_declarator_list
	: init_declarator 
	| init_declarator_list ',' init_declarator
	;


init_declarator
	: IDENTIFIER  '=' assignment_expression		
		{
			if(tempno > 0 && literal == -1){
				fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
				fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
				tempno++;
			}
			//else if(tempno==0 || literal==0){
			else{
				fprintf(fp_icg, "%s = %s\n", $1, $3); 
				fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $3, $1);
				literal = -1;
			}
			
		}			
	| IDENTIFIER
	;


assignment_expression
	: conditional_expression		{	strcpy($$, $1); }
	| unary_expression assignment_operator assignment_expression 		
		{
			switch(assignop){
				case 0: if(tempno > 0 && literal==-1){
							fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
							fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
							tempno++;
						}
						//else if(tempno == 0){
						else{
							fprintf(fp_icg, "%s = %s\n", $1, $3); 
							fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", $3, $1);
							literal=-1;							
						}
						break;

				case 1: 
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;
					
						break;
				case 2:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 3:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s * %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 4:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s / %s\n",buffer, $1, $3);
						fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s %c %s\n",buffer, $1, '%',$3);
						fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%', $1, $3, buffer);

						fprintf(fp_icg, "%s = t%d\n", $1, --tempno); 
						fprintf(fp_quad, "\t=\t\tt%d\t\t  \t\t%s\n", tempno, $1);
						tempno++;

						break;
			}
			
			assignop = -1;

			
		}
	;


assignment_operator
	: '='			{ assignop = 0; 	}
	| ADD_ASSIGN	{ assignop = 1; 	}
	| SUB_ASSIGN	{ assignop = 2; 	}
	| MUL_ASSIGN	{ assignop = 3; 	}
	| DIV_ASSIGN	{ assignop = 4; 	}
	| MOD_ASSIGN	{ assignop = 5; 	}
	;


conditional_expression
	: equality_expression 	{	strcpy($$, $1);  }
	;


expression_statement
	: ';'				
	| expression ';' 	
	;


expression
	: assignment_expression		{	strcpy($$, $1); }
	| expression ',' assignment_expression 
	;


primary_expression
	: IDENTIFIER 			{	literal=0;strcpy($$, $1); 	}
	| INTEGER_LITERAL		{	literal=0;strcpy($$, $1); 	}
	| FLOAT_LITERAL			{	literal=0;strcpy($$, $1); 	}
	| CHARACTER_LITERAL		{	literal=0;strcpy($$, $1); 	}
	| '(' expression ')'	{	literal=0;strcpy($$, $2); 	}
	;


postfix_expression
	: primary_expression		{	strcpy($$, $1); }	
	| postfix_expression INC_OP	
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + 1\n",buffer, $1);
			fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", $1, buffer);

			fprintf(fp_icg, "%s = %s\n", $1, buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, $1);
			
		}
	| postfix_expression DEC_OP 
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - 1\n",buffer, $1);
			fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", $1, buffer);

			fprintf(fp_icg, "%s = %s\n", $1, buffer);
			fprintf(fp_quad, "\t=\t\t%s\t\t  \t\t%s\n", buffer, $1);
		}
	;


unary_expression
	: postfix_expression				{	strcpy($$, $1); }
	| unary_operator unary_expression 
		{
			switch(unaryop){
				case 1: 
						sprintf(buffer,"t%d",tempno++);	
						m = strlen(buffer);
						buffer[m] = '\0';					
						fprintf(fp_icg, "%s = -%s\n",buffer, $2);	
						fprintf(fp_quad, "\t-\t\t%s\t\t  \t\t%s\n", $2, buffer);
						strncpy($$, buffer, m+1);						
						break;

				case 4: 
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s + 1\n",buffer, $2);
						fprintf(fp_quad, "\t+\t\t%s\t\t1 \t\t%s\n", $2, buffer);
						strncpy($$, buffer, m+1);		//check out
						break;

				case 5:
						sprintf(buffer,"t%d",tempno++);
						m = strlen(buffer);
						buffer[m] = '\0';
						fprintf(fp_icg, "%s = %s - 1\n",buffer, $2);
						fprintf(fp_quad, "\t-\t\t%s\t\t1 \t\t%s\n", $2, buffer);
						strncpy($$, buffer, m+1);		//check out
						break;
			}
			unaryop = -1;
		}			
	;


unary_operator
	: '+' 		{	unaryop = 0; }
	| '-'		{	unaryop = 1; }	%prec UMINUS
	| '!'		{	unaryop = 2; }
	| '~'		{	unaryop = 3; }
	| "INC_OP"	{	unaryop = 4; }
	| "DEC_OP" 	{	unaryop = 5; }
	;


equality_expression
	: relational_expression		{	strcpy($$, $1); }
	| equality_expression EQ_OP relational_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s == %s\n", buffer, $1, $3);
			fprintf(fp_quad, "\t==\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| equality_expression NE_OP relational_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s != %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t!=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;


relational_expression
	: additive_expression		{	strcpy($$, $1); }
	| relational_expression '<' additive_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s < %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t<\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression '>' additive_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s > %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t>\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression LE_OP additive_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s <= %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t<=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| relational_expression GE_OP additive_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s >= %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t>=\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}		
	;


additive_expression
	: multiplicative_expression		{	strcpy($$, $1); }
	| additive_expression '+' multiplicative_expression 	
		{
			// printf("%s + %s\n", $1, $3 );
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s + %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t+\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	| additive_expression '-' multiplicative_expression	
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s - %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t-\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}
	;


multiplicative_expression
	: unary_expression			
	| multiplicative_expression '*' unary_expression 
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s * %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t*\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}						
	| multiplicative_expression '/' unary_expression	
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s / %s\n",buffer, $1, $3);
			fprintf(fp_quad, "\t/\t\t%s\t\t%s\t\t%s\n", $1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}										
	| multiplicative_expression '%' unary_expression
		{
			sprintf(buffer,"t%d",tempno++);
			m = strlen(buffer);
			buffer[m] = '\0';
			fprintf(fp_icg, "%s = %s %c %s\n",buffer, $1, '%',$3);
			fprintf(fp_quad, "\t%c\t\t%s\t\t%s\t\t%s\n", '%',$1, $3, buffer);

			strncpy($$, buffer, m+1);		//check out
		}						
	;


function_definition
	: type_specifier declarator compound_statement 					
	| declarator compound_statement 								
	;

function_call
	: declarator '(' identifier_list ')'
		{
			paramno++;	
			fprintf(fp_icg, "call(%s, %d)\n", $1, paramno);	
			fprintf(fp_quad, "\tcall\t\t%s\t\t%d\n", $1, paramno);

			paramno = 0;	
		}	
	| declarator '(' ')'
		{
			fprintf(fp_icg, "call(%s, 0)\n", $1);	
			fprintf(fp_quad, "\tcall\t\t%s\t\t0\n", $1);
		}
	;


declarator
	: IDENTIFIER 	
		{ 
			m = strlen($1);
			strncpy($$, $1, m);	
			$$[m] = '\0';
		}
	| declarator '(' parameter_list ')'		
		{
			
		}	
	| declarator '(' identifier_list ')'				
	| declarator '(' ')'					
	;


parameter_list
	: parameter_declaration						
	| parameter_list ',' parameter_declaration	
	;


parameter_declaration
	: type_specifier IDENTIFIER		
	| type_specifier				
	;


identifier_list
	: IDENTIFIER		
		{
			fprintf(fp_icg, "param %s\n", $1);
			fprintf(fp_quad, "\tparam\t\t%s\n", $1);
		}				
	| identifier_list ',' IDENTIFIER	
		{
			fprintf(fp_icg, "param %s\n", $3);
			fprintf(fp_quad, "\tparam\t\t%s\n", $3);	
			
			paramno++; 
		}
	;


%%


void yyerror(const char *str){
	fflush(stdout);
	printf("Line:%d: ", line);
	printf("\033[1;31m");
	printf("error: ");
	printf("\033[0m");
	printf("%s\n", str);
}


int main(){
	
	fp_icg 	 	= fopen("icg.txt", "w+");
	fp_quad		= fopen("quad.txt", "w+");
	printf("\n");
	

	fprintf(fp_quad, "\tOp\t\topr1\t\topr2\t\tResult\n");
	fprintf(fp_quad, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

	yyparse();
	
	fclose(fp_icg);
	


	printf("\n\nQuadruple Format\n\n");
	
	

	fclose(fp_quad);
	system("cat quad.txt");
		printf("\n\nIntermediate Code\n\n");
	system("cat icg.txt");
	
	return 0;
}

