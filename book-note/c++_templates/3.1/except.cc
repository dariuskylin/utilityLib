/*Copyright 2012 NDSL. All Rights Reserved.
 * =====================================================================================
 *       Filename:  except.cc
 *    Description:  
 *        Version:  1.0
 *        Created:  11/06/2012 03:11:47 PM
 *         Author:  dongyuchi (dongyuchi), dongyuchi@gmail.com
 *        Company:  UESTC.NDSL
 * =====================================================================================
 */
#include<iostream>
#include<stdexcept>

class MyExcept {
    public:
        void throwMe() {
            throw std::out_of_range("heihei,kengni de");
        }
};

int  main() {
    MyExcept except;
    try {
        except.throwMe();
    }
    catch(std::exception const& ex) {
        std::cerr << "Exception:..." <<ex.what() << std::endl;
    }
    return 0;
}
