import os
import win32api
path = os.path.dirname(os.path.realpath(__file__))
def dealWithFile(url,file):
	print(file)
	os.chdir(url)
	#paramsH=path+"\External\ispc.exe "+os.path.splitext(file)[0]+".ispc -h "+os.path.splitext(file)[0]+".h"
	#params=path+"\External\ispc.exe "+os.path.splitext(file)[0]+".ispc --emit-c++ --target=generic-16 -o "+os.path.splitext(file)[0]+".h"
	#print(paramsH)
	#os.system(paramsH) #生成头文件
	#paramsCPP=path+"\External\ispc.exe "+os.path.splitext(file)[0]+".ispc --emit-c++ --target=generic-4 -o "+os.path.splitext(file)[0]+".cpp"
#	os.system(paramsCPP)#生成Cpp文件
	#paramsCPP=path+"\External\ispc.exe "+os.path.splitext(file)[0]+".ispc -o "+os.path.splitext(file)[0]+".obj"+" --arch=x86"
	paramsCPP=path+"\External\ispc -O2 "+os.path.splitext(file)[0]+".ispc"+" -o "+os.path.splitext(file)[0]+".obj"+" -h "+os.path.splitext(file)[0]+".h"+" --target=sse4,avx2,avx512skx-i32x16 --opt=fast-math"
	print(paramsCPP)
	os.system(paramsCPP)#生成Cpp文件

def walk(url, prefix):
    fl = os.listdir(url) # get what we have in the dir.
    for f in fl:
        if os.path.isdir(os.path.join(url,f)): # if is a dir.
            walk(os.path.join(url,f), '')
        else:
            if os.path.splitext(f)[1] == '.ispc':
            	dealWithFile(url,f)

if __name__ == "__main__": 
    walk(path,'')
    print(path+"搜索结束！")