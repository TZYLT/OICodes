@echo off

for /r "E:\WorkSpace" %%a in (*.cpp) do (
type %%a >> E:\TEST\sum.cpp

)

pause