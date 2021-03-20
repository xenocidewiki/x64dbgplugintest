#include "plugin.h"

static duint kurwa(int argc, const duint* argv, void* userdata)
{
    if(argc < 2)
        return 0;

    auto sum = argv[0] + argv[1] + argv[2];

    return sum;
}

static bool kurwa2(ExpressionValue* result, int argc, const ExpressionValue* argv, void* userdata)
{
    if (argc < 2)
        return 0;

    auto sum = argv[0].number + argv[1].number + argv[2].number;
    result->type = ValueTypeNumber;
    result->number = sum;

    return true;
}

//Initialize your plugin data here.
bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    if (!_plugin_registerexprfunction(pluginHandle, "kurwa", 3, kurwa, nullptr))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the stack.contains expression function!");

    ValueType arr[3] = { ValueTypeNumber, ValueTypeNumber, ValueTypeNumber };
    if (!_plugin_registerexprfunctionex(pluginHandle, "kurwa2", ValueTypeNumber, arr, 3, kurwa2, nullptr))
        _plugin_logputs("[" PLUGIN_NAME "] Error registering the stack.contains expression function!");

    return true; //Return false to cancel loading the plugin.
}

//Deinitialize your plugin data here.
void pluginStop()
{

}

//Do GUI/Menu related things here.
void pluginSetup()
{
}
