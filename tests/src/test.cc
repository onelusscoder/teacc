//
// Created by lsc on 21-01-29.
//

#include "test.h"

test::test(int argc, char **argv) : application(argc, argv)
{

}


//test::~test()
//{
//
//}



teacc::diagnostics::application::status test::run()
{
    return application::run();
}



auto main(int argc, char** argv) -> int {
    
    test app(argc, argv);
    app.run();
    return 0;
}
