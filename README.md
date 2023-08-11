# libasm (42 Project graded 100/100)

Little library write in asm using nasm (x86_64).<br>
Tests are written in c using miniunit.

---

### List of functions

- ft_strlen (man 3 strlen)
- ft_strcpy (man 3 strcpy)
- ft_strcmp (man 3 strcmp)
- ft_write (man 2 write)
- ft_read (man 2 read)
- ft_strdup (man 3 strdup)

---

### How to use

Compile library:
```
make
```

Run tests:
```
make test
```

---
### ⚠️ WARNING ⚠️

It's partially working on mac arm:
- change the name of the function to _ft (
- syscall doesn't work because syscall codes are not the same (for write and read)
