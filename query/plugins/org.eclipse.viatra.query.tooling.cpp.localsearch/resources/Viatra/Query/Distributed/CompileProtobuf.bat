for %%f in (*.proto) do (
protoc "%%~nf.proto" --cpp_out=.
)
pause
	