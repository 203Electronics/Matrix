cd /d "%~dp0"
.\sketch_combiner\bin_merge_tool\mergesketch.exe .\bootloader_only_binaries\matrix_fastboot.bin %~f1 .\..\bootloader_and_software_build\%~n1_with_bootloader.bin

pause