#taken from https://twiki.cern.ch/twiki/pub/LHCPhysics/TtbarNNLO/massdep-param.py.txt

# arXiv:1303.6254
#
# \sigma(m) = \sigma(m_ref) (m_ref / m)^4 \times (1 + a_1 ((m-m_ref)/m_ref) + a_2 ((m-m_ref)/m_ref)^2)
#
#
#


def xsect_vs_mt(  x,  par ):
    # par[0] = m_ref
    # par[1] = sigma(m_ref)
    # par[2] = a_1
    # par[3] = a_2
    sigma= (par[1])*((par[0]/x[0])**4)*(1+par[2]*(x[0]-par[0])/(par[0]) + par[3]*(((x[0]-par[0])/(par[0]))**2) )
    return sigma_mt


#https://twiki.cern.ch/twiki/pub/LHCPhysics/TtbarNNLO/rootsdep-param.py.txt
# cross section vs. sqrt(s)
# parameterized after: Langenfeld, Moch, Uwer, Proc. DIS2009
#
def xsect_vs_sqrts(  x,  par ):
    from math import log
    sqrts = x[0] * 1000.
    logE  = log( sqrts/14000. )
    logE2 = logE*logE
    sigma_s = par[0] + sqrts * ( par[1] + par[3] * logE + par[4] * logE2 ) + sqrts * sqrts * ( par[2] + par[5] * logE + par[6] * logE2 )
    return sigma_s
    
    
import numpy as np
import matplotlib.pyplot as plt

    
X = np.linspace(1.0, 14.0, num=1000)
sigma_sqrts = []
energy=[]
sigma_py=[]
for i in X:
	if i >0:
		#energy = 13/i
		sigma_s = xsect_vs_sqrts(  [i],  [-18.8,0.0039,4.95e-6,-0.004820,0.00193168,1.68e-6,-1.799e-6] )
		if sigma_s>0:
			print(i , sigma_s)

			#plt.plot(i, sigma_s, 'o')

#plt.yscale('log')
#plt.show()


#to run the code use python xsection_plots.py > outfile.dat




