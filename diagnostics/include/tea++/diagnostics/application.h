//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_APPLICATION_H
//#define TEACC_APPLICATION_H


#pragma once
#include <tea++/utils/colors.h>
#include <tea++/utils/expect.h>

#include <tea++/diagnostics/diagnostic.h>


namespace teacc::diagnostics
{

/*!
 * @brief base class of he diagnostics/tests application framework.
 *
 */
class application
{
public:
    
    using status = expect<diagnostic::code>;
    
    application() = default;
    application(int argc, char** argv);
    
    
    virtual ~application() = default;
    
    virtual status run();
    
};

}
//#endif //TEACC_APPLICATION_H
