import matplotlib.pyplot as mtplt

number_sort = []
lst = []
bst = []

dataset = open('ot.txt', 'r')

for line in dataset:
    line = line.strip()
    NS, LS, BST = line.split(' ')
    number_sort.append(int(NS))
    lst.append(int(LS))
    bst.append(int(BST))


fig, ax = mtplt.subplots()

ax.set_title('List x BST')
ax.set_xlabel('Número Gerado')
ax.set_ylabel('Número de Comparações')

color = 'tab:blue'
ax.scatter(number_sort, lst, color = color, label = "List")

color = 'tab:red'
ax.scatter(number_sort, bst, color = color, label = "BST")

ax.legend()

mtplt.show()
