from distutils.core import setup, Extension
module1=Extension('exmod',
        include_dirs=['/usr/local/include'],
        libraries=  ['pthread'],
        sources=['exmodmodule.c'])

setup(name='exmod',
      version='1.0',
      description='Hello world',
      author='soliduscode',
      url='http://www.soliduscode.com',
      ext_modules=[module1])
