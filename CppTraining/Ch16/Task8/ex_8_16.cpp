#include "ex_8_16.h"
#include "../My_classes_16/Convert.h"

void ex_8_16() {
    Convert conv(Point{ 10,10 });
    conv.wait_for_button();
}