################################################

CC = gcc
FLAGS = -Wall -Wextra -Werror -O2 
INCL = ./includes/
CFLAGS = -I $(INCL) $(FLAGS) 

################################################

NAME_CHK = checker
NAME_PSWAP = push_swap

################################################

PATH_SRC = src/
PATH_SORT = src/sort/
PATH_UTILS = src/utils/
PATH_FUNC = src/funcDLClist/
PATH_GNL = gnl/

################################################


SRC	=	push_swap.c \
		validInit.c

FUNC	=	funcList_1.c \
			funcList_2.c \
			funcList_3.c

UTILS	=	ft_split.c \
			utils.c \
			utils_1.c

SORT	=	sort.c \
			sort_1.c \
			sort_utils_1.c \
			options.c

SRC_GNL	=	get_next_line_utils.c \
			get_next_line.c

################################################

SRC_PS	=	$(addprefix $(PATH_SRC), $(SRC)) \
			$(addprefix $(PATH_SORT), $(SORT)) \
			$(addprefix $(PATH_UTILS), $(UTILS)) \
			$(addprefix $(PATH_FUNC), $(FUNC))

SRC_CHK	=	src/checker.c \
			$(addprefix $(PATH_GNL), $(SRC_GNL)) \
			$(addprefix $(PATH_FUNC), $(FUNC))\
			$(addprefix $(PATH_UTILS), $(UTILS)) \
			src/sort/sort_utils_1.c \
			src/validInit.c


OBJ_PS	=	$(SRC_PS:.c=.o)
OBJ_CHK	=	$(SRC_CHK:.c=.o)

OBJ_PATH	=	$(OBJ_CHK) $(OBJ_PS)

################################################


all : $(NAME_PSWAP)

$(NAME_CHK) : $(OBJ_CHK)
	$(CC) -o $(NAME_CHK) $(OBJ_CHK) $(CFLAGS)

$(NAME_PSWAP) : $(OBJ_PS)
	$(CC) -o $(NAME_PSWAP) $(OBJ_PS) $(CFLAGS)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME_CHK)
	@rm -rf $(NAME_PSWAP)

re: fclean all

bonus: $(NAME_CHK)

.PHONY: all re clean fclean step step2 step3 step4 step5 step6 step7 dance

################################################

define RIK_1
----------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
---------------------------------------------------------------------------------------------------- 
-------------------------::-------/----------------------------------------------------------------- 
-------------------------+-::----/-/---------------------------------------------------------------- 
-------------------------/``.::-:-`-/--------------------------------------------------------------- 
-------------------------/````.::```/--::----------------------------------------------------------- 
-------------------/:::::/``..---------::----------------------------------------------------------- 
-------------------::``````---`````.-:.+------------------------------------------------------------ 
---------------------/-```/.``.--:::::o/::---------------------------------------------------------- 
--------------------::/.`:.``/+::/-.:://::---------------------------------------------------------- 
----------------:::-`````/```:`   -/    /----------------------------------------------------------- 
-----------------/::---``/```:`  /-:-  s/----------------------------------------------------------- 
-------------------:::-``/.``-/:::..::/o/----------------------------------------------------------- 
------------------/:-.``-:-``....``:-:.+------------------------------------------------------------ 
----------------------:::--.````````..`+------------------------------------------------------------ 
----------------------:/::::``````-.:/./------------------------------------------------------------ 
------------------------:+:/:.````.:/:/------------------------------------------------------------- 
--------------------::.````-:-:--..-/:-------------------------------------------------------------- 
-------------------:-    `--::-/o`:  ./------------------------------------------------------------- 
-------------------/    `: -.``./ `- --------------------------------------------------------------- 
-------------------/   `:  -.```/   :: /------------------------------------------------------------ 
-------------------:   :   -.```/    + /------------------------------------------------------------ 
-------------------:   -.  -.```/    .:/------------------------------------------------------------ 
-------------------/   `// :````/  --/ -------------------------:+osyhhhhys+:----------------------- 
-------------------o    /` :````/  -./  /---------------------/yhhhhhhhhhhhhhy+--------------------- 
-------------------o.   :  /````/    :` /--------------------ohhhyo+/:/+++oyhhhy:------------------- 
------------------/.:   : --````/    /  /-------------------shho-.`````..``.:shhh:------------------ 
------------------/ :   :`/`````/   -/  --------------------hh+.`````--..-.``.+hho------------------ 
-----------------/` :   `+-`````/  .-:   /------------------d/-.-..`::.   .-```ohs------------------ 
----------------:`  :    +``````:``---   /------------------y:   `:`-.    .-```:o+------------------ 
---------------:`   -`   :``````:`` :/   :------------------/`   `:.`.-..-.`````./------------------ 
-------------::     .:   :``````:`  //   -:-----------------:/...-.:--`:+``````/:------------------- 
------------::     -//   :....--+`  /:.   /------------------:-.```.-/sds.```./:-------------------- 
-----------::     +mmo   `/:hddd+`  /-:   /--------------------::..oys+-``..-:::-------------------- 
-----------/    `oyyhy    yshhy.-`  +-/   :----------------------::::::-----````:/------------------ 
----------/    -yyyyyh    oyyh.  : .:-+   .:-------------------------+````-.``````::---------------- 
---------/`   -hyyyyyh.   /yyyy: : :--:.   +------------------------::`:``:.```-```./--------------- 
---------:   -./yyyyy+:   -yyyyyo+ /---:   /------------------------+``.+./````/`````/:------------- 
--------/.   :  +yyyyyo    :/yyyyy++---/   :------------------------+```+/+````/``````/------------- 
--------+   :    oyyyys    : .oyyyyyo:-+   -:-----------------------/---/-+:---:```````/------------ 
--------/   :    `syyyh    :   :syyyyyo//--+-------------------------/./---+../````````./----------- 
--------/  -`     `syyh`   /    `/yyyyyys.-o-------------------------:`/---/``/`````````::---------- 
--------/  :       `syyo---/      -yyyyyo..::------------------------:`/---/``/``````````+---------- 
--------/  :        `yyy-..+`     `//syo.```::-----------------------:`/---/``/``````````/----------
--------/ `-         -yh/...--`   `/--+/+/`:./:----------------------:`/---/``/````````.-s:--------- 
--------:-`-     ```.-+h/.```//`   +---/yy-:./+----------------------:`/---/``/.....-:ohmmo--------- 
---------/ :  `---::---+ho-`:+/----+----+y-y.o-----------------------:`/---+``hhyhhdmmmmmm:--------- 
----------::.::---------hy://+----------oosh+------------------------:`/-/hy``dNNmmmmmmds:---------- 
----------:o/----------+yy+y/:----------shyy+-----------------------/.`-hmmo``/dmmmmmy/------------- 
-----------------------syyyy/-----------hyyh:----------------------:/ohhdmN+//+hmmdo---------------- 
-----------------------hyyh/-----------:hyyh-----------------------ymmmmmdmmmhsmy/------------------ 
----------------------oyyyy------------oyyyy----------------------/mmmmh+mmmmms:-------------------- 
----------------------yyyy+------------syyys-----------------------smmmmsdmmmh---------------------- 
---------------------:hyyh:------------yyyyo------------------------ommmmyhmmmh--------------------- 
---------------------+soyo-------------yssy/-------------------------/dmmmyhmmmh:------------------- 
---------------------/``+--------------+``+---------------------------:hmmmyymmmh:------------------ 
--------------------:o..+--------------o..o-----------------------------ymhy:ommmh------------------ 
--------------------dmddd/------------ymddmh+:---------------------------+:-/:/ho//----------------- 
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/---------------- 
-------------------smmmmmmmmy--------:hddmmmmmms----------------------/-----/-`````/----------------
--------------------:////////------------:::::------------------------------::::::::----------------
---------------------------------------------------------------------------------------------------- 
----------------------------------------------------------------------------------------------------
endef

define RIK_2
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
-------------------------:--------/-----------------------------------------------------------------
-------------------------/-::----/-/----------------------------------------------------------------
-------------------------/``-::-::`-:---------------------------------------------------------------
-------------------------/````-:/```+---:-----------------------------------------------------------
-------------------/:::::+``...----.:--/:-----------------------------------------------------------
-------------------::``````---.````---`/------------------------------------------------------------
---------------------/.```:.`..-:::::/o/:-----------------------------------------------------------
--------------------::/.`:.``/+/:/--:://::----------------------------------------------------------
-----------------::-.````/```:`   -/`  `/-----------------------------------------------------------
----------------::::---``/```:   /-/.  o/-----------------------------------------------------------
-------------------::::``/```-:.---.::/o+-----------------------------------------------------------
------------------//-.``./-``..--``:-:.+------------------------------------------------------------
---------------------::::--.````````..`+------------------------------------------------------------
----------------------:+--:-``````-.-/./------------------------------------------------------------
-------------------------+:o:.````-:/:/-------------------------------------------------------------
------------------------::-/:-:----:::--------------------------------------------------------------
--------------------::.`  `-::./o.-::---------------------------------------------------------------
-------------------:-    `--.`.-/ .  ./-------------------------------------------------------------
-------------------/    `- -.```/ `-`-:-------------------------------------------------------------
-------------------/   `-  -.```/   -/`/------------------------------------------------------------
-------------------:   :   -.```/    `:/------------------------------------------------------------
-------------------:   -.  :.```/   `:./------------------------------------------------------------
-------------------/   `:/ :````/  .:: --------------------------/osyhhhhhyo/-----------------------
-------------------s    +  /````/    :` /----------------------ohhhhhhhhhhhhhho:--------------------
------------------/-.   : .:````/    /  /--------------------/yhhys+/::/++oshhhh+-------------------
------------------/ :   : :`````/   .+  /-------------------:hhs/.`````..-`.-ohhho------------------
-----------------/` :   -.:`````/  `::  --------------------+do-`````.--.--.``:hhd------------------
---------------::`  :   `/``````/ `-..   /------------------ss-..-.``::   `:```:hd------------------
-------------::`    :    /``````/ ` --   /------------------o/    .-`:`   `:```.oy------------------
-----------:-`      :`   /``````:   :/   :------------------/.    --`.-..--.`````/------------------
---------::`       :h:   :....../   /+   -:------------------+----.-:-`-/.`````-::------------------
--------::       `ohd+   ::yyyy//   //.   /-------------------:.```.-/ohy-````-/--------------------
--------/       .syyyo   `hhhd/ :  ---/   /--------------------::..+ys+:``..--::--------------------
-------/.      .yyyyys    yyyy. :  /--/   :-----------------------::-:------.``.::------------------
-------/      .yyyyyyd    oyyyy::  /--+   .:------------------------::`````````:`-/-----------------
-------:     .-.yyyyyd.   /syyyys. +--:.   +------------------------+``````:```/``./----------------
-------/     :  /yyyyy/   -`+yyyyy+:---:   /------------------------/``/```/```:.```::--------------
-------/    :    oyyyyo    : .syyyys:--/   :------------------------/``.o``/```.:````-/-------------
-------:-   :    `syyys    :  `+yyyyy+-+   -:-----------------------/:--+/`::--::`````-/------------
--------/  `-     .yyyy    :    -syyyys//--+-------------------------/./-:-`/../```````-/-----------
---------: :       -yyh`   /     -syyyyys.-o-------------------------/`:--+`/``/````````::----------
---------/`:        :yyo---/     --/syyyo..::------------------------/`:--::/``/`````````::---------
----------/-`        +yy-..+`    :---+yo.```::-----------------------/`:---:+``/``````````+---------
----------:-: `.--::::yh/...--`  :----::+/`:`/:----------------------/`:----+``/```````-:oh---------
-----------/+::-------/h/.```/+--/-----/yy-:./+----------------------/`:----/``/``..:oydmmm---------
------------+----------+ho-`:+:---------+y-y.o-----------------------/`:---/s``hsyhdmmmmmms---------
------------------------hy://+----------oosh+------------------------/`:-/ymd``dNNmmmmmds/----------
-----------------------+yy+y/:----------shyy+-----------------------/-`-ymmm+`.:dmmmmdo-------------
-----------------------syyyy/-----------hyyh------------------------/ohhhmmNoo/+hmmy/---------------
-----------------------hyyh/-----------:hyyh-----------------------smmmmmhdmmmdyms:-----------------
----------------------oyyyy------------oyyyy-----------------------hmmmm/ymmmmdo--------------------
----------------------yyyy+------------syyys-----------------------:hmmmd+mmmms---------------------
---------------------:hyyh:------------yyyys-------------------------hmmmdommmm+--------------------
---------------------+soyo-------------yssy/--------------------------ymmmdsmmmm/-------------------
---------------------/``+--------------+``+----------------------------smmmdommmm/------------------
--------------------:o..+-------------:o..o-----------------------------omhy:+mmmd------------------
--------------------dmddd/------------ymddmy+:---------------------------+:-/:/ho//-----------------
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/----------------
-------------------smmmmmmmmy--------/hddmmmmmms----------------------/-----/-`````/----------------
--------------------:///////:------------:::::------------------------------::::::::----------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
endef

define RIK_3
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
-------------------------:--------/-----------------------------------------------------------------
-------------------------+-::----/-/----------------------------------------------------------------
-------------------------/``.::-::`-/---------------------------------------------------------------
-------------------------/````.::```/--::-----------------------------------------------------------
-------------------/:::::+``..---------::-----------------------------------------------------------
-------------------::``````---.````.--`+------------------------------------------------------------
---------------------/-```/.``.---::::o/::----------------------------------------------------------
--------------------::/.`:.``/+///--/://::----------------------------------------------------------
----------------:::-`````/```:`   -/`   /-----------------------------------------------------------
----------------::::---``/```:   /-/.  o/-----------------------------------------------------------
-------------------:::-``/```-/-::-.::/o+-----------------------------------------------------------
------------------/:-.``-:-``....``:-:.+------------------------------------------------------------
---------------------::::--.````````..`+------------------------------------------------------------
----------------------:/--::``````-.:/./------------------------------------------------------------
----------------------:::+-+:.````.:/:/-------------------------------------------------------------
---------------------:.````-:-:--..-/:--------------------------------------------------------------
-------------------::    `--::-/o`:` ./-------------------------------------------------------------
-------------------/    `: --`../ `- ---------------------------------------------------------------
-------------------/   `:  --```/   :: /------------------------------------------------------------
-------------------:   :   -.```/    + /------------------------------------------------------------
-------------------:   -.  -.```/    .:/------------------------------------------------------------
-------------------/   `/: :.```/  --/ -:-------------------------/osyhhhhhys+----------------------
-------------------o    /` :````/  -./  /-----------------------+hhhhhhhhhhhhhhs:-------------------
-------------------o.   :  /````/    :` /---------------------/yhhyo/:--:+++shhhho------------------
------------------/.:   : --````/    /  /---------------------hhy:.``````.-..-ohhhs-----------------
------------------/ :   -`/`````/   -/  ---------------------:d/-..```.-..--.``:hhh:----------------
-----------------:` :   `+-`````/  .-:   /-------------------oy.``.-``:/   `:```:hh/----------------
------------:-.``   :    +``````:``-.-   /-------------------+.    .-`:`   `:```.yh-----------------
----------:.`       -`   :``````:`` :/   /-------------------/:````--`.--..-.```..+-----------------
--------:-         `::   :``````:`  //   -:-------------------/-...`:-..:/``````-::-----------------
--------:         :hs+   :.`````/`  /:.   /--------------------/.``.:/oydo````.-:-------------------
-------/        `odmms   `+ssoo/+  `/-/   /---------------------::--oo+:.``..--:::------------------
-------/       .syyyyy    hddds`:  :--/   :------------------------:::-------````/------------------
-------/      -yyyyyyh    oyyh` :  /--+   .:------------------------+````````````::-----------------
-------/     .+yyyyyhh.   /yyyy::  +--:.   +------------------------/`.``````-```-:-----------------
-------/     : /yyyyyy:   -yyyyyy.`/---:   /------------------------/`/``````/```-+-----------------
-------/    -`  +yyyyyo    :/yyyyys:---/   :------------------------/`--`````/```-:/----------------
--------:   :    oyyyys    : .oyyyyyo:-+   .:-----------------------//-+`````::-::../---------------
--------/   :    `syyyh    :   :syyyyyo:/--+-------------------------+`./`````/`/.``.::-------------
---------: `-     `syyh`   /    `/yyyyyys.-o-------------------------+``+:````/`/.````.::-----------
---------/``-      `syyo---/     `+oyyyyo..::------------------------+``/::```/`/.``````-/:---------
----------: :       `yyy-..+`    `/-/syo.```::-----------------------+``/-::.`/`/.``````.sd/--------
-----------:/  ``.---/yy/...--`   /---+/+/`:./:----------------------+``/---:-/`/.````-+dmmm/-------
------------+/:-:-----+h/.```/+-``/----/yy-:./+----------------------+``/----:/`/--:+ydmmmmm+-------
-------------/---------+ho-`:+:--::-----+y-y.o-----------------------+``/--:oh+`/mmNmmmmmmh/--------
------------------------hy///+----------oosh+------------------------+``+:sdmm+`-mNmmmmmh+----------
-----------------------+yy+y/:----------shyy+------------------------/`.:mmmmm..-/mmmms/------------
-----------------------syyyy/-----------hyyh:-----------------------+/hmdmmmyyhs/omdo---------------
-----------------------hyyh/-----------:hyyh------------------------smmmmho/dmmmms/-----------------
----------------------oyyyy------------+yyyy------------------------:mmmms-hmmmd/-------------------
----------------------yyyy+------------syyyy-------------------------+mmmm/+mmmm:-------------------
---------------------:hyyh:------------yyyys--------------------------+mmmd:ymmmy-------------------
---------------------+soys-------------yssy/---------------------------smmmy:mmmm+------------------
---------------------/``+--------------+``+-----------------------------ymmm+ommmd------------------
--------------------:o..+--------------o..o-----------------------------:hyo/-ymmms-----------------
--------------------dmddd/------------smddmy+----------------------------::./:-yo:+-----------------
-------------------+mmmmmmh+---------:mmmmmmmdo-----------------------::-`  `+:-..-/----------------
-------------------smmmmmmmmy--------:hdmmmmmmms----------------------/-----/-`````/----------------
--------------------:////++//------------:::::------------------------------::::::::----------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
endef

export RIK_1
export RIK_2
export RIK_3

step step2 step3 step4 step5 step6 step7:
	@clear
	@echo "$$RIK_1"
	@sleep 0.15
	@clear
	@echo "$$RIK_2"
	@sleep 0.15
	@clear
	@echo "$$RIK_3"
	@sleep 0.15
	@clear
	@echo "$$RIK_2"
	@sleep 0.15

dance: step	step2 step3	step4 step5 step6 step7

################################################
