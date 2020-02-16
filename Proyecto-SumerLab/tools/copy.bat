@echo  off

copy %1 %3 /y
mkdir %3\assets
xcopy %2 %4 /s /y

echo archivos copiados