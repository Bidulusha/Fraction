# Fractions for c++
**This library is realization of fractoins in c++**

## Source files for build .so an .o
*Source files in **src/** folder.*


### .o file
To compile cpp file to ***.o*** file use
```
g++ fraction.cpp -c -o /path/to/output/folder/fraction.o
```

### .so file
To compile cpp file to ***.so*** file use
```
g++ -fPIC fraction.cpp -shared -o /path/to/output/folder/libfrac.so
```

To use ***.so** file in linux create symlink in /usr/lib/
```
ln -s /absolute/path/to/fraction.so /usr/lib
```
or move ***.so*** file to /usr/lib
```
mv fraction.so /usr/lib/
```

And don't forget create symlink to include/fraction or src/fraction.hpp or another fraction header file in /usr/include/
```
ln -s /absolute/path/to/fraction.hpp /usr/include/
```

## Compile files c++ that include library
if you are using ***.o***
```
g++ my_file.cpp -Irelative/path/to/include relative/path/to/fraction.o -o output_file_name
```

if you are using ***.so*** (don't forget create symlink or move to /usr/lib/)
```
g++ my_file.cpp -Irelative/path/to/include -lfrac -o output_file_name
```


#


*Config for cmake in progress!*
