#ifndef SAVE_H
#define SAVE_H
#include "player.h"

typedef struct {

} Save;


void saveGame(Player *player);
void loadGame(Player *player, Supemon *supemon1, Supemon *supemon2, Supemon *supemon3, Supemon *supemonEnemy1, Supemon *supemonEnemy2, Supemon *supemonEnemy3, Items *item1, Items *item2, Items *item3, Move *move1, Move *move2, Move *move3, Move *move4, Move *move5, Move *move6, Move *move7, Move *move8, Move *move9, Move *move10);

#endif


import tkinter as tk
import random
import re

class Fleissner:
    def __init__(self, root):
        self.root = root
        self.root.title("Grille Tournante Cryptographique")
        self.n = int(input("Entrez la taille de la grille: "))
        self.labels = self.createGrid(self.n)
        self.randomLabels(self.n)
        self.setup_widgets()

    def createGrid(self, n):
        labels = []
        for row in range(n):
            row_labels = []
            for col in range(n):
                label = tk.Label(self.root, padx=20, pady=10, borderwidth=2, relief="groove")
                label.grid(row=row, column=col, sticky="nsew")
                row_labels.append(label)
            labels.append(row_labels)
        return labels

    def randomLabels(self, n):
        randomN = n * n // 4 if n % 2 == 0 else (n * n - 1) // 4
        for _ in range(randomN):
            row = random.randint(0, n-1)
            col = random.randint(0, n-1)
            selected_label = self.labels[row][col]
            selected_label.config(bg='red')  # Marquer le label sélectionné

    def setup_widgets(self):
        self.entry = tk.Entry(self.root, width=50)
        self.entry.grid(row=self.n, column=0, columnspan=self.n, sticky="ew")
        filter_button = tk.Button(self.root, text="Filtrer et Afficher", command=self.filter_text)
        filter_button.grid(row=self.n+1, column=0, columnspan=self.n, sticky="ew")
        self.result_label = tk.Label(self.root, text="Filtré: ")
        self.result_label.grid(row=self.n+2, column=0, columnspan=self.n, sticky="ew")

    def filter_text(self):
        input_text = self.entry.get()
        filtered_text = re.sub('[^a-zA-Z]', '', input_text)
        self.result_label.config(text=f"Filtré: {filtered_text}")

def main():
    root = tk.Tk()
    app = Fleissner(root)
    root.mainloop()

if __name__ == "__main__":
    main()
