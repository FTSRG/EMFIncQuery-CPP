echo off
for %%f in (*.proto) do (
echo on
protoc "%%~nf.proto" --cpp_out=.
)
pause
	