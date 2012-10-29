/*
 * =====================================================================================
 *
 *       Filename:  pre_1.1.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/17/2012 01:34:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC
 *
 * =====================================================================================
 */
#include<iostream>
#include<cassert>

template< typename type, int dim >
class Point{
    public:
        Point();
        Point( type coords[ dim ] ) {
            for( int index = 0; index < dim; index++ )
                _coords[ index ] = coords[ index ];
        }

        const type& operator[](int index) const  {
            assert( index < dim && index >= 0 );            
            return _coords[ index ];
        }

    private:
        type _coords[ dim ];
};

template< typename type, int dim>
std::ostream& 
operator<<( std::ostream &os, const Point< type, dim > &pt ){
    os<<"(";
    for( int ix = 0; ix < dim-1; ix++ ){
        os<< pt[ ix ]<<", ";
    }
    os << pt[ dim - 1 ];
    os<<" )";
}

