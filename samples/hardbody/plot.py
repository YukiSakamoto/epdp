#!/usr/bin/env/python

import sys

import numpy
import scipy.io
from matplotlib.pylab import *


N_A = 6.0221367e23

def plot_data( N, T, fmt ):

    mean = T.mean(1)
    std_err = T.std()/math.sqrt(len(T))

    #errorbar( N, mean, yerr=std_err, fmt=fmt )
    print N, mean
    loglog( N, mean, fmt )


T=0.001
V=40e-15
#N=100
#C=

Nv = numpy.array([30,100,300,1000,3000,10000,30000,100000,300000])

#constant V
data_V = numpy.array([\
        #t=1e-1
        [0.00175549983978,0.00199764966965,0.00246767044067],
        #t=1e-2
        [0.011493897438,0.0130080938339,0.0142705917358],
        [0.0880681991577,0.0914797067642,0.0762763023376],
        [0.632449603081,0.688769006729,0.711854600906],

        #t=1e-3
        [4.32058787346,4.54254817963,4.46804094315],
        [35.3325610161,37.1281208992,36.7095458508],
        [293.817239046,309.815385818,301.104192972],

        #t=0.0001
        [4076.65598154,3982.7852416,4332.7786088],

        #t=0.00001
        [69639.7185087,68016.7577028,67395.1318979],
        ])

Nc = numpy.array([30,100,300,1000,3000,10000,30000,100000,300000])#,1000000])
#constant C
data_C = numpy.array([\
        #40e-17, t=1e-2
        [0.0353735923767,0.0389065027237,0.0432499885559],

        #13e-16
        [0.162874937057,0.147514104843,0.242296934128],

        # 40e-16
        [0.449470043182,0.461053848267,0.449807167053],

        # 13e-15
        [1.69260191917,1.50591206551,1.48942518234],

        #V=40e-15, N=3000
        [4.32058787346,4.54254817963,4.46804094315],

        # 13e-14, 10000
        [16.7206249237,15.2708730698,15.4511377811],

        # 40e-14, 30000
        [49.2036440372,45.7764439583,47.7596070766],

        [177.116400957,172.534185886,175.979680061],
        
        # t=1e-4
        [1488.63044024,1484.78682995,1563.27685833],
        # t=1e-5
        #[81783.0754995,78885.0462198,0],
        ])


# (40e-18 ** (1/3.0))**2 / 1e-12
# = 11.69607095285148
data_V *= 11.696/1e-3
data_C *= 11.696/1e-3

Nb = numpy.array([10,30,100,300,1000,3000,10000])#,30000,100000])
data_bd_5 = numpy.array([\
        #t=1e-8, dt = 1e-5 tau
        [0.0485391616821,0.0476109981537,0.0482919216156],
        [0.138695001602,0.139840841293,0.139472007751],
        [0.45738196373,0.454463005066,0.458449840546],
        [1.35839486122,1.36714601517,1.36983513832],
        [4.74575400352,4.73176693916,4.71269416809],
        [14.96296978,14.7860958576,14.9349989891],
        [50.471544981,51.1204040051,51.8594009876],
#        [0,0,0],
#        [0,0,0]]
        ])
data_bd_5 *=  11.696/ 1e-8
data_bd_6 = data_bd_5 * 10

X = numpy.array([5,100,300,1000,3000,10000,30000,100000,5e6])

#for i in range( len(Nv) ):
plot_data( Nv, data_V,'kx' )
#loglog( X, 0.15* X**(5.0/3), 'k--' )
loglog( X, 0.004* X**(6.0/3), 'k--' )

figtext( .3, .17, r'(2) V = 40 fL' )
figtext( .8, .74, r'$t \ \propto \ N^{5/3}$', color='k' )


#for i in range( len(Nc) ):
plot_data( Nc, data_C,'ko' )
loglog( X, 17* X, 'k-' )

figtext( .135, .34, r'(1) C = 100 nM' )
figtext( .8, .6, r'$t \  \propto \ N$', color='k' )

#plot_data( Nb, data_bd_6,'k.' )

loglog( X, 5e7* X, 'b:' ) # 1e-6 tau
loglog( X, 5e4* X, 'b:' ) # 1e-3 tau

figtext( .2, .78, r'BD', color='k' )

figtext( .2, .61, r'BD (relaxed)', color='k' )

#loglog( data1[0] , data1[1], 'o-', label='Vol. = 1e-15 L' )
#loglog( data2[0] , data2[1], 'o-', label='# particles = 600' )
#loglog( data3[0] , data3[1], 'o-', label='Conc. = 1e-6 M' )

xlabel( 'N [# particles]' )
#xlabel( 'Concentration [M]' )
ylabel( 'time [sec]' )
#legend()
xlim(4,1e7)
ylim(1.1,2e11)

grid()

Cx3000=numpy.array([
    9.35e-11,
    9.35e-10,
    9.35e-9,
    9.35e-8,#N=3000,V=40e-15
    9.35e-7,#N=3000,V=40e-16
    9.35e-6,#N=3000,V=40e-17
    9.35e-5,#N=3000,V=40e-18
    9.35e-4

    ])
data_N3000 = numpy.array([\
        [0,0,0],
        #t=1e-2
        [0.218799996376,0.224667906761,0.232618093491],
        [0.868317198753,0.8549451828,0.859500288963],

        #t=1e-3
        [4.32058787346,4.54254817963,4.46804094315],
        [26.2109909058,25.985396862,21.6751132011],

        [585.424571037,660.102545023,601.128531218],
        # t=0.0001
        [14289.9441504,19102.6055598,2176.95770907],
        # t=0.000001
        [292934.114933,293264.955997,291557.028055]
        ])

Cx300=numpy.array([
    9.35e-10,#N=300,V=40e-14
    9.35e-9,#N=300,V=40e-15
    9.35e-8,#16
    9.35e-7,#17
    9.35e-6,#18
    9.35e-5,#19
    9.35e-4,#20
    3.74e-3#1e-21
    #9.35e-3,#4e-21
    ])
data_N300 = numpy.array([\
        #t=0.01, 14
        [0.0224853992462,0.0231349945068,0.0233565807343],
        [0.0808939218521,0.098435997963,0.10002450943],

        #t=0.001, 16
        [0.42756986618,0.459966897964,0.345192193985],
        [1.89058303833,2.22953391075,2.1871380806],

        # 18
        #[33.5733759403,49.6112761497,41.7061488628],
        [58.1811749935,46.0744490623,0],

        #t=0.0001
        #[1731.63747787,1731.17349148,1693.01162958],
        [1598.15320969,2163.40493917,1901.36489868],
        
        #t=1e-5
        #[20535.3760004,21186.9897127,23196.2311029],
        [22880.3765059,22880.3765059,22880.3765059],
        [0,0,0]
        #[474846.178055,491588.463068,473160.961151]
        ])

data_N3000 *= 11696
data_N300 *= 11696

axes([.61,.21,.27,.28])

# M-> uM
Cx300 *= 1e6
Cx3000 *= 1e6

for i in range( len(Cx3000) ):
    plot_data( Cx3000, data_N3000,'k+' )
#loglog( Cx3000, 5e1** Cx3000, 'b:' )
bd3000 = numpy.array([17.1796619892,17.4832251072,17.5032970905]).mean()
bd3000 *= 11.69607 / 1e-9
loglog( [1e-4,1e4],[bd3000,bd3000], 'b:' )


for i in range( len(Cx300) ):
    plot_data( Cx300, data_N300,'kd' )
loglog( Cx300, 2.5e4* Cx300**(2.0/3.0), 'k-.', label='C^(4/3)' )
loglog( Cx300, 2.5e4* Cx300**(4.0/3.0), 'k-.', label='C^(4/3)' )

figtext( .73, .22, r'(3a) N = 300' )
figtext( .79, .28, r'$t \ \propto \ C^{2/3}$', color='k' )
figtext( .62, .35, r'(3b) N = 3000' )

#bd 300
bd300 = numpy.array([1.62390208244,1.62284588814,1.63388109207]).mean()
bd300 *= 11.69607 / 1e-9
loglog( [1e-5,1e5],[bd300,bd300], 'b:' )

figtext( .63, .405, r'BD', color='k' )

xlabel( 'Concentration [uM]' )
ylabel( 'time [sec]' )

#xlim(5e-10,5e-2)
#ylim(1e2,5e9)
#xlim(5e-10,5e-3)
xlim(2e-4,9e3)
ylim(2e2,8e11)

show()
#savefig('fig1.eps')




#>>> _gfrd.S_irr( .0001 * 1e-8**2/1e-12, 1e-8, 10 * 1e-8 * 1e-12, 1e-12, 1e-8 )
#0.99116163945434221


