#Some words are in Portuguese, but I will translate with comments

class Node:
    def __init__(self, chave = None, dado = None, R = None, L = None, Pai = None, cor = 'V'):
        self.chave = chave
        self.dado = dado
        self.R = R
        self.L = L
        self.Pai = Pai
        self.cor = cor

    def setDado(self, val):
        self.dado = val

    def getDado(self):
        return self.dado

    def getChave(self):
        return self.chave
    
    def setR(self, no):
        self.R = no
    
    def getR(self):
        return self.R
    
    def setL(self, no):
        self.L = no
    
    def getL(self):
        return self.L
    
    def setPai(self, no):
        self.Pai = no
    
    def getPai(self):
        return self.Pai
    
    def setCor(self, string):
        self.cor = string
    
    def getCor(self):
        return self.cor

class ArvoreTricolor:
    def __init__(self):
        self.raiz = None
        self.vazio = Node(None, None, None, None, None, 'P')
    
    def insert(self, chave, dado):
        element = Node(chave, dado)
        if self.raiz == None:
            self.raiz = element
            element.setR(self.vazio)
            element.setL(self.vazio)
            element.setPai(self.vazio)
        else:
            current = self.raiz
            while current != self.vazio:
                posicao = current
                if chave > current.getChave():
                    current = current.R
                else:
                    current = current.L
            if element.getChave() > posicao.getChave():
                posicao.setR(element)
            else:
                posicao.setL(element)
            element.setPai(posicao)
            element.setR(self.vazio)
            element.setL(self.vazio)
        self.insert_fixup(element)

    def delete(self, chave):
        y = chave
        y_cor_original = y.getCor()
        if chave.getL() == self.vazio:
            x = chave.getR()
            self.transplant(chave, chave.getR())
        elif chave.getR() == self.vazio:
            x = chave.getL()
            self.transplant(chave, chave.getL())
        else:
            y = self.minimum(chave.getR())
            y_cor_original = y.getCor()
            x = y.getR()
            if y.getPai() == chave:
                x.setPai(y)
            else:
                self.transplant(y, y.getR())
                y.setR(chave.getR())
                y.getR().setPai(y)
            self.transplant(chave, y)
            y.setL(chave.getL())
            y.getL.setPai(y)
            y.setCor(chave.getCor())
        if y_cor_original == 'P':
            self.delete_fixup(x)

    def delete_fixup(self, x):
        while x != self.raiz and x.getCor() == 'P':
            if x == x.getPai().getL():
                w = x.getPai().getR()
                if w.getCor() == 'V':
                    w.setCor('P')
                    x.getPai().setCor('V')
                    self.LeftRotate(x.getPai())
                    w = x.getPai().getR()
                if w.getL().getCor() == 'P' and w.getR().getCor() == 'P':
                    w.setCor('V')
                    x = x.getPai()
                elif w.getR().getCor() == 'P':
                    w.getL().setCor('P')
                    w.setCor('V')
                    self.RightRotate(w)
                    w = x.getPai().getR()
                    w.setCor(x.getPai().getCor())
                    x.getPai().setCor('P')
                elif w.getR().getCor() ==  'V':
                    w.setCor('V')
                    w.getPai().setCor('P')
                w.getR().setCor('P')
                self.LeftRotate(x.getPai())
                x = self.raiz
            else:
                w = x.getPai().getL()
                if w.getCor() == 'V':
                    w.setCor('P')
                    x.getPai().setCor('V')
                    self.LeftRotate(x.getPai())
                    w = x.getPai().getL()
                if w.getR().getCor() == 'P' and w.getL().getCor() == 'P':
                    w.setCor('V')
                    x = x.getPai()
                elif w.getL().getCor() == 'P':
                    w.getR().setCor('P')
                    w.setCor('V')
                    self.LeftRotate(w)
                    w = x.getPai().getL()
                    w.setCor(x.getPai().getCor())
                    x.getPai().setCor('P')
                elif w.getL().getCor() ==  'V':
                    w.setCor('V')
                    w.getPai().setCor('P')
                w.getL().setCor('P')
                self.RightRotate(x.getPai())
                x = self.raiz

    def minimum(self, x):
        while x.getL() != None:
            x = x.getL()
        return x
    
    def search(self, chave, Nome = None):
        current = self.raiz
        while current != self.vazio and (current.getChave() != chave or current.getDado()[0] != Nome):
            if chave <= current.getChave():
                current = current.getL()
            else:
                current = current.getR()
        return current

    def transplant(self, u, v):
        if u.getPai() == self.vazio:
            self.raiz = v #Se não funcionar, bater em ernesto
        elif u == u.getPai().getL():
            u.getPai().setL(v)
        else:
            u.getPai().setR(v)
        v.setPai(u.getPai())

    def insert_fixup(self, dado):
        element = dado
        while element.getPai().getCor() == 'V':
            if element.getPai() == element.getPai().getPai().getL():
                current = element.getPai().getPai().getR()
                if current.getCor() == 'V':
                    element.getPai().setCor('P')
                    current.setCor('P')
                    element.getPai().getPai().setCor('V')
                    element = element.getPai().getPai()
                elif element == element.getPai().getR():
                    element = element.getPai()
                    self.LeftRotate(element)
                    element.getPai().setCor('P')
                    element.getPai().getPai().setCor('V')
                    self.RightRotate(element.getPai().getPai())
            else:
                current = element.getPai().getPai().getL()
                if current.getCor() == 'V':
                    element.getPai().setCor('P')
                    current.setCor('P')
                    element.getPai().getPai().setCor('V')
                    element = element.getPai().getPai()
                elif element == element.getPai().getL():
                    element = element.getPai()
                    self.RightRotate(element)
                    element.getPai().setCor('P')
                    element.getPai().getPai().setCor('V')
                    self.LeftRotate(element.getPai().getPai())
        self.raiz.setCor('P')
        
    def LeftRotate(self, element):
        current = element.getR()
        element.setR(current.getL())
        if current.getL() != self.vazio:
            current.getL().setPai(element)
        current.setPai(element.getPai())
        if element.getPai() == self.vazio:
            self.raiz = current
        elif element == element.getPai().getL():
            element.getPai().setL(current)
        else:
            element.getPai().setR(current) 
        current.setL(element)
        element.setPai(current)

    def RightRotate(self, element):
        current = element.getL()
        element.setL(current.getR())
        if current.getR() != self.vazio:
            current.getR().setPai(element)
        current.setPai(element.getPai())
        if element.getPai() == self.vazio:
            self.raiz = current
        elif element == element.getPai().getR():
            element.getPai().setR(current)
        else:
            element.getPai().setL(current)
        current.setR(element)
        element.setPai(current)

#Pai = Dad
#dado = data
#chave = key
#vazio = empty
#Cor = color
#no = Node
#Val = value
