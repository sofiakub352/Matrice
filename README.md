# Matrice
        
---Jocul Stacks---

 Componentele utilizate in realizarea acestui proiect sunt:
- Arduino Uno
- Cablu Arduino USB
- Matrice de leduri 8x8
- Driver MAX7219
- LCD display
- Potentiometru
- Push button
- Condensator 10 uF
- Rezistente 10K, 220 Ohm
- Condensator 0.1 uF
- Trei breadboard-uri
- Fire de conexiune

 Cum functioneaza jocul:
- exista 4 nivele diferentiate prin dimensiunea piesei de baza(situata pe ultimul rand al matricei), care sta pe loc pe tot parcursul nivelului
- pe fiecare rand in parte, pornind de la penultimul, o alta piesa de dimensiunea bazei parcurge toate coloanele pana cand este apasat butonul, moment in care piesa ramane pe locul selectat
- cand se ajunge la primul rand al matricei este verificata corectitudinea asezarii pieselor, iar in cazul in care asezarea este gresita,
se reincepe nivelul
- daca jucatorul reuseste sa treaca de cel de-al patrulea nivel, castiga jocul
- pentru a juca din nou, trebuie apasat butonul
- numarul vietilor ramase este afisat pe LCD
- numarul nivelului este afisat pe matrice la inceperea acestuia

 Regula jocului:
Jucatorul are la dispozitie 5 vieti pe care le poate pierde in doua cazuri: 
- daca butonul nu a fost apasat pana cand piesa trece de ultima coloana a matricei 
- daca dupa terminarea nivelului, in urma verificarii, nu exista cel putin o coloana de leduri aprinsa complet, care porneste din baza

Video:
https://drive.google.com/file/d/1N-P-53446kBn94WY90s5X1yWCR0Fc45J/view?usp=sharing


 ---Stacks Game---
 
 Components used for this project are:
- Arduino Uno
- USB Arduino Cable
- Led Matrix 8x8
- Driver MAX7219
- LCD display
- Potentiometer
- Push button
- Condenser 10 uF
- Resistor 10K, 220 Ohm
- Condenser 0.1 uF
- Three breadboards
- Connection wires

 How the game works:
- there are four levels, each having a different base piece size(located on the last row of the matrix), that doesn't move during the game
- on every remaining row, one by one, another piece (with the same size as the base) moves through all the columns, until the button is pressed, selecting where the piece should stay
- when the first row of the matrix is reached, the game checks if the pieces are in the right place. If not, the same level starts again
- at the end of the fourth level, the player wins the game
- in order to play again, the button has to be pressed again
- the number of hearts left is printed on the LCD
- the current level is displayed on the matrix at the beginning of every level
 
 Rules of the game:
The player starts with 5 hearts, that can be lost in two cases:
- if the button isn't been pressed until the piece reaches the last column of the matrix
- if the current level ends and there isn't at least one full column of leds on, that begins from the base

Video:
https://drive.google.com/file/d/1N-P-53446kBn94WY90s5X1yWCR0Fc45J/view?usp=sharing
