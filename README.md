<p align="center">
  <img src="https://avatars.githubusercontent.com/u/85075638" width="280" alt="Scapetown Logo" style="border-radius:50%" />
</p>

## Description
Ardruino firmware for controlling the lock door.

- controlling a servo (door)
- reading a num pad and displaying it on the screen 

#### What is scapetown?
Scapetown is one of the largest escape rooms in the world, created by secondary school students. [Learn more](https://jegaathetmaken.nl/scapetown/)

## Protocol specification

> **Legend:**
>
> `-->` ardruino-to-server (send)
>
> `<--` server-to-ardruino (receive)
> 
> `<-->` ardruino-to-server and server-to-ardruino (send and receive)

`-->`

| key       | type     | desc                                             |
|-----------|----------|--------------------------------------------------|
| `@`       | `string` | Show first character as a '*'                    |
| `#`       | `string` | Show second character as a '*'                   |
| `$`       | `string` | Show third character as a '*'                    |
| `%`       | `string` | Show fourth character as a '*'                   |
| `&`       | `string` | Show fifth character as a '*'                    |
| `[`       | `string` | Clear first line and set cursor to (0, 0)        |
| `]`       | `string` | Clear second line and set cursor to (0, 1)       |
| `(`       | `string` | Set servo (door) to OPEN position                |
| `)`       | `string` | Set servo (door) to CLOSE position               |
| `*`       | `string` | write other character at current cursor position |

`<--`
| key       | type     | desc                                             |
|-----------|----------|--------------------------------------------------|
| `*`       | `string` | Send any character and display it on the LCD     |


## Required

- platform IO

## Author
- [Martijn Faber](https://github.com/Martijn-Faber)

## License

Scapetown is [MIT licensed](LICENSE).