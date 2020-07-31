from re import findall
import sys

class PreAssembler:

    def __init__(self):
        self.oper = {  'arith':{
                                '+':'ADD',
                                '*':'MUL',
                                '-':'SUB',
                                '/':'DIV'
                            },
                    'cond':{
                                '==':'BNE',
                                '!=':'BE',
                                '<':'BGE',
                                '>':'BLE',
                                '<=':'BGT',
                                '>=':'BLT'
                            }
                }

        self.regVal = {'R0':None, 'R1':None, 'R2':None, 'R3':None, 'R4':None, 'R5':None, 'R6':None, 'R7':None}
        self.regAvail = ['R0','R1','R2','R3','R4','R5','R6','R7']
        self.regOccup  = []
        self.condition =  ""

    def arithOper(self, line, operation):
        print("Line: ",line)
        print("operation: ",operation)
        register1 = self.reuseRegister(line[2])
        if not register1:
            register1 = self.getFreeRegister()
            self.regVal[register1] = line[2]
        if line[4].isnumeric():
            register2 = line[4]
        else:
            register2 = self.reuseRegister(line[4])
            if not register2:
                register2 = self.getFreeRegister()
                self.regVal[register2] = line[4]
        register3 = self.getFreeRegister()
        print("\t{} {} {} {}".format(operation,register3,register1,register2))

    
        regex_match= findall("^t[0-9]*$",line[0])
        print("re_m",regex_match)
        if(len(regex_match)):
            print("before pass")
            pass
        else:
            print("\tSTR {} {}".format(register3,line[0]))
        
        if line[0] == line[2]:
            regOccup.remove(register1)
            regAvail.append(register1)
            regVal[register1] = None
        
        elif line[0] == line[4] and not line[4].isnumeric():
            regOccup.remove(register2)
            regAvail.append(register2)
            regVal[register2] = None
        self.regVal[register3] = line[0]


    def condOper(self, line):
        register1 = self.reuseRegister(line[2])
        if not register1:
            register1 = self.getFreeRegister()
            self.regVal[register1] = line[2]
        if line[4].isnumeric():
            register2 = line[4]
        else:
            register2 = self.reuseRegister(line[4])
            if not register2:
                register2 = self.getFreeRegister()
                self.regVal[register2] = line[4]
        print("\tCMP {} {}".format(register1,register2))



    def getFreeRegister(self):
        if self.regAvail:
            reg = self.regAvail.pop(0)
            self.regOccup.append(reg)
        else:   
            reg = self.regOccup.pop(0)
            self.regVal[register] = None
            self.regOccup.append(register)
        return reg


    def reuseRegister(self, operand):
        print("Operand:",operand)
        for i in self.regVal:
            if operand == self.regVal[i]:
                print("Reusing")
                reg = i
                return reg
        # reg = self.getFreeRegister()
        # print("\tMOV", reg, operand)
        # self.regVal[reg] = operand
        # return reg

    def printLabel(self, label):
        regex_match = findall("^[A-Za-z0-9]*:$", label)
        if len(regex_match):
            print(label)
        else:
            print('\nLabel ERROR\n')
        return


    def branch(self, label):
        print("\tB", label)


    def assignOper(self, variable, value):
        register1 = self.reuseRegister(value)
        print("R1:",register1)
        if not register1:
            register1 = self.getFreeRegister()
            self.regVal[register1] = value
            print("\tMOV", register1, value)
        print("\tSTR", register1, variable)
        regex_match= findall("^t[0-9]*$", value)
        print("RE_M",regex_match)
        if value.isnumeric() or len(regex_match):
            print("Before pass")
            pass
        else:
            register2 = self.getFreeRegister()    
        for register in self.regVal:
            if self.regVal[register] == variable:
                self.regVal[register] = None
                self.regOccup.remove(register)
                self.regAvail.append(register)
                break
                
        if not value.isnumeric() and not len(regex_match):
            self.regVal[register2] = variable
        if self.regVal[register1].isnumeric() or len(regex_match):
            self.regOccup.remove(register1)
            self.regOccup.append(register1)
            self.regVal[register1] = variable


    def translate(self, instr):
        instr = instr.split()
        print(instr)
        if len(instr) == 1:
            self.printLabel(instr[0])
        
        if len(instr) == 2:
            if instr[0] == 'goto':
                self.branch(instr[1])
            else:
                print("\nBranch ERROR\n")
        
        if len(instr) == 3:
            if '=' in instr:
                self.assignOper(instr[0], instr[2])
            else:
                print("\nAssignment ERROR\n")
            return 
        
        if len(instr) == 4:
            if 'ifFalse' in instr:
                print("\t{} {}".format(self.condition, instr[3]))
            else:
                print("\nERROR\n")
            return  

        if len(instr) == 5:
            for operator in self.oper['arith']:
                if operator in instr:
                    print(operator)
                    self.arithOper(instr, self.oper['arith'][operator])
                    return

            for operator in self.oper['cond']:
                if operator in instr:
                    print("Cond",self.oper['cond'][operator])
                    self.condition = self.oper['cond'][operator]
                    self.condOper(instr)
                    return
            print("\nERROR\n")
            return


inputCode = []

preAssemb = PreAssembler()

inputFile = sys.argv[1]
with open(inputFile, 'r') as f:
    inputCode = f.readlines() 
    print(inputCode,"\n")

for i in inputCode:
    preAssemb.translate(i)
