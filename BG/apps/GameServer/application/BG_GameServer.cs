﻿using Common.common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Application
{
    public class BG_GameServer
    {
        public static void Initialize(BG_Options option)
        {
            Console.WriteLine("Hello World from BG_GameServer!");
        }

        public static async void Run()
        {
            while (isRunning)
            {

                await Task.Delay(1);
            }
        }

        public static void End()
        {
            Console.WriteLine("end BG_GameServer!");
        }

        private static bool isRunning = false;
    }
}
