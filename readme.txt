Подключаем glut к проекту на VC++
http://www.programbeginner.ru/?p=234


1. Скопируйте в папку System вашей Windows файл из этого архива glut32.dll.
2. Теперь нам нужно указать среде, что мы будем использовать эту библиотеку. Найдите в каталоге, в который вы установили вашу VC++ вложенные директории include\Gl и lib.
У меня это примерно так: D\Program Files\Microsoft Visual Studio 9.0\VC\include\GL и
D:\Program Files\Microsoft Visual Studio 9.0\VC\lib
3. Скопируйте из архива файлы glut32.lib в Program Files\Microsoft Visual Studio 9.0\VC\lib и glut.h
в Program Files\Microsoft Visual Studio 9.0\VC\include\GL
Теперь важные файлы лежат по своим местам. Как не парадоксально, но это все. Теперь в наших VC++ проектах можно использовать glut. Для этого нужно просто подключить вначале проекта загаловочный файл #include<gl/glut.h>.