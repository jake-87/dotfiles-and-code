import ctypes
import pathlib
libname=pathlib.Path().absolute()
lib =  ctypes.CDLL(libname)
print(csquare(10))
