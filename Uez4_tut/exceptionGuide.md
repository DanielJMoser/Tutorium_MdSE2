# The Big Guide to Exceptions and Errors (not comprehensive)
#### (in fact, it's really just two approaches to error/exception handling)  


### Errors mittels `if` checken

Dabei checken wir die condition, die den Fehler ev. auslöst, *bevor* wir den Code ausführen.
Anders gesagt: Wir verhindern den Fehler explizit, bevor er passieren kann und unser Code weiterläuft.  
Dieser Ansatz wird auch *defensive programming* genannt.  
  
Werden Fehler erwartet, so ist dies ein angenehm leserlicher Ansatz, welcher recht wenig Overhead produziert.  
Es ist eigentlich meist nicht üblich, Exceptions mittels `if` zu checken, wie es meistens in diesem Programm gehandhabt wird –
kommt aber auf den Anwendungsfall an. Oft wird so nur ein Error abgefangen, um den Code weiterlaufen zu lassen...
z.B. um mittels *cerr* eine Fehlermeldung auszugeben und anschließend das Programm weiterlaufen zu lassen.  


### Errors mittels `try` checken

Ein Codeblock wird mit `try` umschlossen, und ein `catch`-Block fängt die Exception ab.
Dieser Ansatz ist das eigentliche *exception handling*.  
Code, welcher Exceptions werfen könnte, wird somit vom restlichen Code getrennt.
Error-Handling wird zentralisiert und ist somit leichter zu warten und zu debuggen.



```python