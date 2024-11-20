for %%i in (1,2,3,4,5) do (
A.exe < t1_%%i.in > t1.out
fc t1_%%i.ans t1.out
)
pause