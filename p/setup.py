from distutils.core import setup, Extension

module1 = Extension('datapack', sources = ['datapackmodule.c'])

setup (name = 'Datapack',
        version = '1.0',
        description = 'Minimal package to pack data tightly for transport',
        ext_modules = [module1])


