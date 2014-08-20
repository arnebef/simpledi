import os
env = Environment()

env.Append(CPPPATH = ['include/'])
env.Append(CPPFLAGS = ['-std=c++11'])
env["CXX"] = "clang++"
env['ENV']['TERM'] = os.environ['TERM']

lib = env.SharedLibrary(target='lib/simpledi',source=Glob('src/*.cpp'))

example = env.Program(target='bin/example',source=Glob('example/*.cpp'), LIBS=[lib])

Default(lib)
Default(example)
