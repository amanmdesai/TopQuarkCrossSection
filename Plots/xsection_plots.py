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
    return sigma


#https://twiki.cern.ch/twiki/pub/LHCPhysics/TtbarNNLO/rootsdep-param.py.txt
# cross section vs. sqrt(s)
# parameterized after: Langenfeld, Moch, Uwer, Proc. DIS2009
#
def xsect_vs_sqrts(  x,  par ):
    from math import log
    sqrts = x[0] * 1000.
    logE  = log( sqrts/14000. )
    logE2 = logE*logE
    sigma = par[0] + sqrts * ( par[1] + par[3] * logE + par[4] * logE2 ) + sqrts * sqrts * ( par[2] + par[5] * logE + par[6] * logE2 )
    return sigma
