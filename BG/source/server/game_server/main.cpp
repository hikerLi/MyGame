
#include "bg_common_global_context.h"
#include "framework/bg_framework.h"
int main(int argc, void* argv[])
{
	BG::Framework framework;
	framework.initialize(argc, argv);
	framework.begin();
	framework.run();
	framework.end();
	return 0;
}