# American Literature Adventure Game

An interactive text-based adventure game exploring major movements in American literature, created for academic analysis and engagement.

## Overview

This game allows players to explore different paths through American literary history:
- **Gothic/Dark Romantic**: Poe, Hawthorne, Melville
- **Realism**: Twain, James, Howells  
- **Transcendentalism**: Emerson, Thoreau

## Features

- **Visual Interface**: Images accompany each scene
- **Interactive Choices**: Player decisions affect the narrative path
- **Literary Analysis**: Built-in opportunities for critical thinking
- **Educational Content**: Accurate representation of literary movements
- **Standalone Executable**: Easy distribution and running

## Quick Start

### For Professors/Users (Running the Game)
1. Download the game folder
2. Double-click `LiteratureAdventure.exe` (if available)
3. OR run `python main.py` if you have Python installed

### For Developers (Customizing)
1. Install Python 3.7+
2. Install requirements: `pip install Pillow`
3. Run: `python main.py`

## File Structure

```
literature_adventure/
├── main.py              # Main game engine
├── game_data.py         # Story content and scenes
├── requirements.txt     # Python dependencies
├── assets/             # Image files
│   ├── american_lit_intro.jpg
│   ├── gothic_forest.jpg
│   ├── industrial_city.jpg
│   └── ...
└── README.md           # This file
```

## Creating an Executable

### Windows Users (Recommended):
```bash
pip install pyinstaller
pyinstaller --onefile --windowed --add-data "assets;assets" main.py
```

### Cross-Platform Alternative:
```bash
pip install auto-py-to-exe
auto-py-to-exe
```

This creates a standalone .exe file that runs without Python installation.

## Customization Guide

### Adding New Scenes
Edit `game_data.py` and add to the `scenes` dictionary:

```python
"your_scene_id": {
    "title": "Scene Title",
    "image": "your_image.jpg",
    "text": """Your scene description...""",
    "choices": [
        ("Choice 1 text", "next_scene_id"),
        ("Choice 2 text", "another_scene_id")
    ]
}
```

### Adding Images
1. Place images in the `assets/` folder
2. Reference them in scenes using just the filename
3. Supported formats: JPG, PNG, GIF, BMP
4. Images auto-resize to fit display

### Modifying Literary Content
The game currently includes:
- **Authors**: Poe, Hawthorne, Melville, Twain, James, Emerson, Thoreau
- **Themes**: Individual vs. society, nature, American identity, social reform
- **Literary Techniques**: Symbolism, allegory, realism, transcendentalism

## Educational Applications

### For Literature Classes:
- **Interactive Analysis**: Students make choices that reflect literary themes
- **Comparative Study**: Different paths show contrasting approaches
- **Critical Thinking**: Decision points encourage deeper analysis
- **Visual Learning**: Images support textual analysis

### Assessment Ideas:
- Have students explain their choice reasoning
- Compare different pathway outcomes
- Analyze how game structure reflects literary themes
- Create additional scenes as assignments

## Technical Details

- **Language**: Python 3.7+
- **GUI Framework**: tkinter (built-in)
- **Image Handling**: Pillow (PIL)
- **Cross-Platform**: Windows, Mac, Linux
- **No Internet Required**: Fully offline

## Troubleshooting

### Common Issues:
1. **Images not loading**: Check that images are in `assets/` folder
2. **Python not found**: Install Python 3.7+ from python.org
3. **Pillow errors**: Run `pip install Pillow`
4. **Executable issues**: Try `--onedir` instead of `--onefile` in PyInstaller

### System Requirements:
- **Memory**: 50MB RAM minimum
- **Storage**: 10MB+ (depending on images)
- **Display**: 1000x700 minimum resolution recommended

## Academic Integration

This game template is designed for:
- **Response Papers**: Interactive exploration supports analytical writing
- **Class Presentations**: Visual and interactive elements engage audiences  
- **Research Projects**: Framework can be extended with additional content
- **Assessment Tools**: Choices can reflect understanding of literary concepts

## Future Expansions

The modular design allows for easy addition of:
- More literary movements (Modernism, Harlem Renaissance, etc.)
- Individual author deep-dives
- Historical context scenes
- Multimedia elements (audio, video)
- Save/load game functionality
- Progress tracking and analytics

## Support

For technical issues or questions about customization, refer to:
- Python documentation: python.org
- tkinter tutorials: online tutorials available
- PyInstaller docs: pyinstaller.readthedocs.io

---

*Created for educational purposes - adapt and modify as needed for your specific literature curriculum and analytical goals.*