from matplotlib import pyplot as plt 

singers = 'Ariana','Selena','Chainsmokers','BTS'
score = [45,20,15,20]
explode = (0.05,0,0,0)

fig , ax = plt.subplots()
ax.pie(score, explode=explode ,labels = singers, autopct='%1.1f%%', shadow=True, startangle=90)
ax.axis('equal')
plt.show()