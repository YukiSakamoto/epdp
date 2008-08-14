#!/usr/bin/env python


from matplotlib.pylab import *


D=[0.25,0.5,1,2,4]

data_0=[
0.862862179761,
0.753491410993,
0.60815952851,
0.445889601095,
0.305622223357
]

data_em6=[
0.788132485945,
0.663137430836,
0.507006568658,
0.335227272727,
0.208129584352
]

data_em4=[
0.44779842834,
0.31161462002,
0.19177344261,
0.111646217941,
0.0709871388007
]



data_em2=[
0.0804020100503,
0.0543882484195,
0.0390695283383,
0.0297150280101,
0.0308418302857
]


data_em1=[
0.0304764199241,
0.0269461077844,
0.0247045664543,
0.0233066617045,
0.0225048923679
]



semilogx( D, data_0, '.', label='t_half=0' )
semilogx( D, data_em6, '.', label='t_half=1e-6 [s]' )
semilogx( D, data_em4, '.', label='t_half=1e-4 [s]' )
semilogx( D, data_em2, '.', label='t_half=1e-2 [s]' )
semilogx( D, data_em1, '.', label='t_half=1e-1 [s]' )


xlim(0.2,5)
xticks(D,[str(i) for i in D])

ylim(0,1)
xlabel(r'diffusion speed ($\mu m^2 / s)$')
ylabel('rebinding ratio')
legend()

show()