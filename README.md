# Matrice
        
---Jocul Stacks---

 Componentele utilizate in realizare acestui proiect sunt:
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
- pentru a juca din nou, jucatorul trebuie sa apese butonul
- numarul vietilor ramase este afisat pe LCD
- numarul nivelului este afisat pe matrice la inceperea acestuia

 Regula jocului:
Jucatorul are la dispozitie 5 vieti pe care le poate pierde in doua cazuri: 
- daca butonul nu a fost apasat pana cand piesa trece de ultima coloana a matricei 
- daca dupa terminarea nivelului, in urma verificarii, nu exista cel putin o coloana de leduri aprinsa complet, care porneste din baza

Video:
https://drive.google.com/file/d/1N-P-53446kBn94WY90s5X1yWCR0Fc45J/view?usp=sharing
