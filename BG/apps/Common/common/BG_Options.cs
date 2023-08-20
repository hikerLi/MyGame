using System.Runtime.InteropServices;
using CommandLine;

namespace Common.common
{
    public class BG_Options
    {
        [Option('s', "server_name", Required = true, HelpText = "The name of the server to run.")]
        public string ServerName { get; set; }

        [Option('i', "inner_addr", Required = true, HelpText = "The inner address to bind.")]
        public string InnerAddress { get; set; }
    }
}