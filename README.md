<p align="center">
  <img src="https://github.com/realgetOff/main/blob/main/Header/Black%20Yellow%20Bold%20Bag%20Fashion%20Sale%20Banner%20(2).png">
</p>

<p align="center">
	<img src="https://img.shields.io/badge/status-finished-cyan"/>
	<img src="https://img.shields.io/badge/evaluated-31%20%2F%2010%20%2F%202024-cyan"/>
	<img src="https://img.shields.io/badge/score-125%2F100-cyan"/>
	<img src="https://img.shields.io/badge/language-C_90.8%25-cyan"/>
	<img src="https://img.shields.io/badge/last_commit-january-cyan"/>
	<a href='https://profile.intra.42.fr/users/mforest-' target="_blank"><img alt='42' src='https://img.shields.io/badge/Intra-100000?style=flat-round&logo=42&logoColor=white&labelColor=000000&color=000000'/></a>
</p>

<p align="center">
	<a href="#about">About</a> •
	<a href="#how-to-use">How to use</a> •
	<a href="#mandatory">Mandatory</a> •
	<a href="#bonus">Bonus</a> •
	<a href="#norminette">Norminette</a> •
	<a href="#contributing">Contributing</a> •
</p>

## ABOUT
This is a server/client system that uses UNIX signals for communication. The server displays its PID and receives decrypted signals as characters, while the client encrypts messages and sends true/false signals using SIGUSR1 or SIGUSR2 to the server's PID.

- [Subject](https://github.com/jotavare/minitalk/blob/master/subject/en_subject_minitalk.pdf) `PDF`
- [References](https://github.com/realgetOff/minitalk) `GitHub`

## HOW TO USE
#### 1º - Clone the repository
```bash
git clone https://github.com/realgetOff/minitalk.git
```

#### 2º - Enter the project folder and run `make`
```bash
cd minitalk
make
```

#### 3º - Run server and copy its PID
```bash
./server
```

#### 4º - Open another terminal, run client, paste the PID and write a message
```bash
./client [SERVER PID] [MESSAGE]
```

#### MAKEFILE RULES

`make` - Compile minitalk **mandatory** files.

`make clean` - Delete all .o (object files) files.

`make fclean` - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

## MANDATORY
- [x] Produce server and client executables.
- [x] The Client must communicate a string passed as a parameter to the server (referenced by its process ID) and display it.
- [x] Use `SIGUSR1` and `SIGUSR2` signals only.

## BONUS
- [x] Add reception acknowledgement system.
- [x] Support Unicode characters.

## NORMINETTE
> At 42 School, it is expected that almost every project is written following the Norm, which is the coding standard of the school.

```
- No for, do...while, switch, case, goto, ternary operators, or variable-length arrays allowed;
- Each function must be a maximum of 25 lines, not counting the function's curly brackets;
- Each line must be at most 80 columns wide, with comments included;
- A function can take 4 named parameters maximum;
- No assigns and declarations in the same line (unless static);
- You can't declare more than 5 variables per function;
- ...
```

* [42 Norms](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf) - Information about 42 code norms. `PDF`
* [Norminette](https://github.com/42School/norminette) - Tool to respect the code norm, made by 42. `GitHub`
* [42 Header](https://github.com/42Paris/42header) - 42 header for Vim. `GitHub`

## CONTRIBUTING

If you find any issues or have suggestions for improvements, feel free to fork the repository and open an issue or submit a pull request.
All credits goes to @jotavare (for the README.md).
