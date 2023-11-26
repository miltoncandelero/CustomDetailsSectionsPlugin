# Custom Details Sections
_Organize the details panel by grouping your variables into custom sections_

## How to use
### Step 1
Make sure you give categories to your variables

### Step 2
Find the configuration in the Editor Preferences and create your custom section

### Step 3
Configure your custom section to point to your actor (or a parent of the actor. For example Pawn sections inherit to Character)

### Step 4
Restart the editor as prompted

## Interesting notes
- You can't use subcategories. The engine doesn't support it. You can only group the base category. The plugin will convert any subcategory into the base category.
- You can overwrite names of your previous sections or of engine sections by giving a new section the same ID of an old one.
    - However, categories get added insted of overwriting the previous ones