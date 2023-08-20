using Common.common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
namespace AppCore.app
{
    internal interface ICoreService
    {
        bool LoadLibrary(string libraryPath);
        bool RunLibrary(BG_Options options);
    }

    internal class CoreService : ICoreService
    {
        private Dictionary<string, Assembly> _libraryAssemblies;

        public CoreService()
        {
            _libraryAssemblies = new Dictionary<string, Assembly>();
        }

        public bool LoadLibrary(string libraryPath)
        {
            try
            {
                Assembly assembly = Assembly.LoadFrom(libraryPath);
                _libraryAssemblies.Add(libraryPath, assembly);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool RunLibrary(BG_Options options)
        {
            if (!_libraryAssemblies.ContainsKey(options.ServerName + ".dll"))
            {
                return false;
            }

            try
            {
                Assembly assembly = _libraryAssemblies[options.ServerName + ".dll"];
                Type type = assembly.GetType(options.ServerName + "BG_" + options.ServerName);

                MethodInfo initMethod = type.GetMethod("Initialize");
                initMethod.Invoke(null, new object[] { options});

                MethodInfo runMethod = type.GetMethod("Run");
                runMethod.Invoke(null, null);

                MethodInfo endMethod = type.GetMethod("end");
                endMethod.Invoke(null, null);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}
