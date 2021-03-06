# FSMs-composition-tool
This application is the graphical user interface for building finite state machines binary compositions via BALM-II.
User paints composition in graphical redactor. Then application generates and execute script (sequence of BALM-II commands and special python script execution), that builds composition.
All files with FSM description have to be in .aut format.

# Установка Ubuntu на виртуальную машину:
1. Скачайте и установите VirtualBox
   https://www.virtualbox.org/wiki/Downloads
2. Скачивайте образ последней Ubuntu
   https://ubuntu.com/download/desktop
3. Создайте виртуальную машину в VirtualBox
   3.1 Задайте имя, путь рабочей папки, Linux, Ubuntu x64 (если процессор 32 битный, то x32)
   3.2 Задайте отведенный объем оперативной памяти (рекомендуется 4, лучше 8, но можно и меньше - будет тупить)
   3.3 Создать новый виртуальный жесткий диск -> VDI -> Динамический -> Выделите место (оптимальнее всего - 50, но если планируете использовать для чего-то ещё, то лучше больше)
   3.4 Создать
4. Укажите образ Ubuntu, скачанные на п.2
5. Выберите Installation -> Minimal Installation.
6. Выберите настройки и дождитесь окончания установки.
   
# Requirments:
1. BALM-II
2. Python3
3. Qt

# The easiest and recommended way to build application:
1. Install BALM-II from deb-package
   - https://ultraespresso.di.univr.it/balmII - deb package and instruction
   - sudo dpkg -i /path/to/deb/file - command for deb package installing
2. Install Qt Creator 
   - One of the instructions: https://www.osradar.com/install-qtcreator-on-ubuntu-20-04-18-04/ (follow all instructions)
3. Install python3 
   - sudo apt install python3
4. Install git
   - sudo apt install git
5. Make folder and clone repository
   - git clone https://github.com/SotnikAP/FSMs-composition-tool
6. Open project via Qt Creator (open .pro file)
   - Open Qt Creator -> Open File or Project -> Select FSMs-composition-tool.pro file
7. Build it

# Launch test example instruction
[Link](https://github.com/SotnikAP/FSMs-composition-tool/blob/master/doc/%D0%A3%D0%BF%D1%80%D0%B0%D0%B2%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5%20%D0%B3%D1%80%D0%B0%D1%84%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B8%D0%BC%20%D1%80%D0%B5%D0%B4%D0%B0%D0%BA%D1%82%D0%BE%D1%80%D0%BE%D0%BC%20%D0%B8%20%D0%B7%D0%B0%D0%BF%D1%83%D1%81%D0%BA%20%D1%82%D0%B5%D1%81%D1%82%D0%BE%D0%B2%D0%BE%D0%B3%D0%BE%20%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%B0.pdf)

#### .aut files for test example are in the folder text_example. There is no need to copy them to the build folder, you can just atach them from whereever you want.

