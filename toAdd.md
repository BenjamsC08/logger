# Maybe
    - [ ] faire le AsyncLogger le mettre les logs en queue est qu'un autre thread les ecrivent
            - il prendra en parametre le type de logger voulu (ConsoleLogger ou FileLogger)
            - permet d'en prendre plusieurs (mais tous gere par le meme thread)
                - peut etre juste prendre un File et un Console ? pour: moins d'erreur possible a gerer, contre : si j'ajoute un autre type de logger faut tout remodifier
