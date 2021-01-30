//
// Created by lsc on 21-01-29.
//

//#ifndef TEACC_TEST_H
//#define TEACC_TEST_H

// Code template modified by oldlonesomecoder.
#pragma once

#include <tea++/diagnostics/application.h>


class test : public teacc::diagnostics::application
{
public:
    test(int argc, char** argv);
    ~test() override;
    
    
    teacc::diagnostics::application::status run() override;
    
};



//#endif //TEACC_TEST_H
