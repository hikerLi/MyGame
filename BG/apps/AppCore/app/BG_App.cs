using CommandLine;
using Common.common;

namespace AppCore.app
{
    class App
    {
        static void Main(string[] args)
        {
            Parser.Default.ParseArguments<BG_Options>(args).WithParsed<BG_Options>(options =>
            {
                CoreService coreService = new CoreService();
                coreService.LoadLibrary(options.ServerName + ".dll");
                coreService.RunLibrary(options);
            });
        }
    }
}