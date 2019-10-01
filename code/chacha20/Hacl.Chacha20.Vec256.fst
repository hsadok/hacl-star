module Hacl.Chacha20.Vec256

open Hacl.Meta.Chacha20.Vec

private
let double_round_256 = double_round_higher #8
private
let chacha20_core_256 = chacha20_core_higher #8 double_round_256
private
let chacha20_init_256 = chacha20_init_higher #8

let chacha20_encrypt_256 = chacha20_encrypt_higher #8 chacha20_init_256 chacha20_core_256
let chacha20_decrypt_256 = chacha20_decrypt_higher #8 chacha20_init_256 chacha20_core_256
