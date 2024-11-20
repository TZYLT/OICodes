for %%i in (1,2,3,4) do (
A.exe < print%%i.in > print.out
fc print%%i.ans print.out
)
pause