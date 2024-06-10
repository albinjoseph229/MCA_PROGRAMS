class Semester:
    def __init__(self):
        print('Constructor called, Semester object created')
        
    def classrep(self, rep1, rep2):
        self.classrep1 = rep1
        self.classrep2 = rep2
        print('Class Rep 1:', self.classrep1)
        print('Class Rep 2:', self.classrep2)
    
    def placementrep(self, rep1, rep2):
        self.placementrep1 = rep1
        self.placementrep2 = rep2
        print('Placement Rep 1:', self.placementrep1)
        print('Placement Rep 2:', self.placementrep2)
        

thirdsem = Semester()


thirdsem.classrep('sivanand', 'revathi')
thirdsem.placementrep('Gracen', 'Merin')
