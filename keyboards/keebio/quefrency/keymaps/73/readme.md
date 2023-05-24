## 73'S QUEFRENCY


Build with:
```sh
qmk build

make keebio/quefrency:unausgeschlafen
```

Flash with:

```sh
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash keebio_quefrency_rev1_unausgeschlafen.hex
sudo dfu-programmer atmega32u4 reset
```
