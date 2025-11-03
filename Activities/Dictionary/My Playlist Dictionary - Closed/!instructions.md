# My Playlist Dictionary - Closed Hashing
# INSTRUCTIONS
by Janie Lane Sabado

[1. Instructions](!instructions.md)

[2. Test Cases](!test_cases.md)

---

## Problem Statement
Create a C program that inserts, deletes, and searches the song genre in a closed hashing dictionary using the cursor-based implementation.

All you have to do is write the following functions inside `myPlaylistDictionary.h`. The main function and struct definitions are already provided.

---

## Objective

- `hash(genre)` – The hash accepts the genre of the song, compares the string to the elements of the `genreTable`, returns the correct index.
- `insert(Song)` – Using the hash function, insert a new `Song` into the playlist at its proper place. Any collisions will be placed at the end of its corresponding hashed list.
- `deleteMember(Song)` – Using the hash function, delete a given `Song` in the playlist.
- `search(Song)` – Using the hash function, search in the dictionary if the given `Song` exists in the playlist.

---

## Tips

### `initDict(VirtualHeap *VH)`
- This function is already given.
- It initializes the primary storage to be empty by assigning the `elem.genre` to `"Empty"`.

### `hash(String genre)`
- Compare the string `genre` to the elements of the given `genreTable`.
- Use the string function `strcmp()`.

### `insert(VirtualHeap *VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- If the given index genre is `"Empty"` or `"Deleted"`, insert as it is.
- Else, the song must be appropriately inserted into the secondary storage, at the end of the given genre list.

### `deleteMember(VirtualHeap *VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- If the given index genre is the `song` to be deleted, update the list appropriately.
- Else, the song must be appropriately deleted from the secondary storage, the `VirtualHeap` updating the variable `avail`.

### `search(VirtualHeap VH, Song song)`
- Use the hash function to receive the proper index for the specified genre.
- Traverse through the secondary storage if necessary.
- **Return 1** if the song exists in the playlist.
- **Return 0** if the song does not exist in the playlist.

---

## Sample Output 1