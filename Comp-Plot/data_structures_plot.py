import matplotlib.pyplot as mtplt

number_sort = []
list = []
bst = []

dataset = open('out.txt', 'r')

for line in dataset:
    line = line.strip()
    NS, LS, BST = line.split(' ')
    number_sort.append(int(NS))
    list.append(int(LS))
    bst.append(int(BST))

number_sort.sort()
list.sort()
bst.sort()

fig, ax = mtplt.subplots()

ax.set_title('BST x List')
ax.set_xlabel('Número Gerado')
ax.set_ylabel('Número de Comparações')

color = 'tab:blue'
ax.scatter(number_sort, list, color = color, label = "List")

color = 'tab:red'
ax.scatter(number_sort, bst, color = color, label = "BST")

ax.legend()

mtplt.show()