@echo off

echo ----------------------------
echo -- Compilation et linkage --
echo ----------------------------

rem ******************************
rem * Compilation des fichiers C *
rem ******************************
sdcc -c -mz80  --peep-file peep-rules.txt source/main.c
sdcc -c -mz80  --std-c11  --peep-file peep-rules.txt source/game.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Scene.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Player.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Sprite.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Global.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Input.c
sdcc -c -mz80  --peep-file peep-rules.txt source/data_rom.c
sdcc -c -mz80  --peep-file peep-rules.txt source/title_screen.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Sound.c
sdcc -c -mz80  --peep-file peep-rules.txt source/Class_Text.c
rem ******************************
rem * linkage des fichier objets *
rem ******************************
sdcc -o sms.ihx -mz80 --no-std-crt0 --data-loc 0xC000 rel/crt0_sms.rel Class_Text.rel rel/PSGlib.rel Class_Sound.rel data_rom.rel Class_Input.rel Global.rel rel/data.rel main.rel SMSlib.lib game.rel Class_Sprite.rel Class_Scene.rel Class_Player.rel title_screen.rel

echo ------------------------------
echo -- Creation du fichier .sms --
echo ------------------------------
ihx2sms sms.ihx out/sms.sms

echo -------------------------------------------
echo -- Destruction des fichiers asm et autre --
echo -------------------------------------------
pause

del *.sym
del *.ihx
del *.lk
del *.noi
del *.rel
del *.lst
del *.asm
del *.map
