//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_APPLICATION_H
//#define TEACC_APPLICATION_H


#pragma once
#include <tea++/utils/colors.h>


namespace teacc::diagnostics
{

/*!
 * @brief base class of he diagnostics/tests application framework.
 *
 */
class application
{
public:
    application();
    application(string_t::collection const& args);
    
    
    virtual ~application();
    
};

}
//#endif //TEACC_APPLICATION_H
