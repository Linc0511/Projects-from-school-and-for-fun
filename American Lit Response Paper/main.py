import tkinter as tk
from tkinter import ttk, messagebox
from PIL import Image, ImageTk
import os
import sys
from game_data import GameData

def resource_path(relative_path):
    """Get absolute path to resource, works for dev and for PyInstaller"""
    try:
        # PyInstaller creates a temp folder and stores path in _MEIPASS
        base_path = sys._MEIPASS
    except Exception:
        base_path = os.path.abspath(".")
    
    return os.path.join(base_path, relative_path)

class LiteratureAdventure:
    def __init__(self):
        self.root = tk.Tk()
        self.root.title("Traveling Through Early American History")
        
        # Start in fullscreen
        self.root.attributes('-fullscreen', True)
        
        # Allow escape key to exit fullscreen
        self.root.bind('<Escape>', self.toggle_fullscreen)
        self.root.bind('<F11>', self.toggle_fullscreen)
        
        self.root.resizable(True, True)
        
        # Dark mode color scheme
        self.bg_color = "#2b2b2b"  # Dark gray background
        self.fg_color = "#e0e0e0"  # Light gray text
        self.accent_color = "#404040"  # Slightly lighter gray for accents
        self.text_bg = "#3a3a3a"  # Text area background
        
        # Configure root background
        self.root.configure(bg=self.bg_color)
        
        # Game state
        self.current_scene = "start"
        self.inventory = []
        self.choices_made = {}
        self.game_started = False
        
        # Load game data
        self.game_data = GameData()
        
        # GUI setup
        self.setup_gui()
        self.show_title_screen()
    
    def setup_gui(self):
        """Create the main game interface"""
        # Configure style for dark mode
        style = ttk.Style()
        style.theme_use('clam')
        
        # Configure ttk styles for dark mode
        style.configure('TFrame', background=self.bg_color)
        style.configure('TLabel', background=self.bg_color, foreground=self.fg_color)
        style.configure('TButton', 
                       background=self.accent_color, 
                       foreground=self.fg_color,
                       borderwidth=1,
                       focuscolor='none',
                       padding=10)
        style.map('TButton',
                 background=[('active', '#505050')],
                 foreground=[('active', '#ffffff')])
        
        # Configure special style for play button
        style.configure('Play.TButton',
                       background='#4a7c59',  # Green-ish color
                       foreground='#ffffff',
                       font=('Times New Roman', 16, 'bold'),
                       padding=20)
        style.map('Play.TButton',
                 background=[('active', '#5a9c69')],
                 foreground=[('active', '#ffffff')])
        
        # Main frame
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # Configure grid weights for responsive design
        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)
        main_frame.grid_rowconfigure(1, weight=1)
        main_frame.grid_columnconfigure(0, weight=1)
        
        # Title label
        self.title_label = ttk.Label(main_frame, 
                                     text="Traveling Through Early American History", 
                                     font=("Times New Roman", 35, "bold"))
        self.title_label.grid(row=0, column=0, pady=(0, 10), sticky=(tk.W, tk.E))
        
        # Content frame (for image and text)
        content_frame = ttk.Frame(main_frame)
        content_frame.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S), pady=(0, 10))
        content_frame.grid_rowconfigure(1, weight=1)
        content_frame.grid_columnconfigure(0, weight=1)
        
        # Image display
        self.image_label = ttk.Label(content_frame)
        self.image_label.grid(row=0, column=0, pady=(0, 10))
        
        # Text display with scrollbar
        text_frame = ttk.Frame(content_frame)
        text_frame.grid(row=1, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        text_frame.grid_rowconfigure(0, weight=1)
        text_frame.grid_columnconfigure(0, weight=1)
        
        self.text_display = tk.Text(text_frame, 
                                    wrap=tk.WORD, 
                                    font=("Times New Roman", 12),
                                    height=10, 
                                    state=tk.DISABLED,
                                    bg=self.text_bg,
                                    fg=self.fg_color,
                                    insertbackground=self.fg_color,
                                    selectbackground=self.accent_color,
                                    selectforeground=self.fg_color,
                                    borderwidth=2,
                                    relief="solid")
        
        scrollbar = ttk.Scrollbar(text_frame, orient="vertical", command=self.text_display.yview)
        self.text_display.configure(yscrollcommand=scrollbar.set)
        
        self.text_display.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        scrollbar.grid(row=0, column=1, sticky=(tk.N, tk.S))
        
        # Buttons frame
        self.buttons_frame = ttk.Frame(main_frame)
        self.buttons_frame.grid(row=2, column=0, pady=(10, 0), sticky=(tk.W, tk.E))
        
        # Status bar
        self.status_var = tk.StringVar()
        self.status_bar = ttk.Label(main_frame, 
                                    textvariable=self.status_var, 
                                    font=("Arial", 10), 
                                    foreground="#909090")
        self.status_bar.grid(row=3, column=0, sticky=(tk.W, tk.E), pady=(5, 0))
    
    def show_title_screen(self):
        """Display the title screen with play button"""
        # Hide text display for title screen
        self.text_display.grid_remove()
        
        # Clear buttons
        for widget in self.buttons_frame.winfo_children():
            widget.destroy()
        
        # Set title - CHANGE THIS LINE TO CUSTOMIZE YOUR TITLE
        self.title_label.configure(text="An Adventure Through Early American History And Litature")
        
        # Load title screen image using resource_path
        title_image_path = resource_path(os.path.join('assets', 'title_screen.webp'))
        if os.path.exists(title_image_path):
            try:
                image = Image.open(title_image_path)
                # Make title image bigger - 600x400
                image.thumbnail((600, 400), Image.Resampling.LANCZOS)
                self.current_image = ImageTk.PhotoImage(image)
                self.image_label.configure(image=self.current_image, text="")
            except Exception as e:
                self.image_label.configure(image="", 
                    text=f"Title Screen\n\nTraveling Through Early American History\n\n(Add title_screen.webp to assets folder)")
        else:
            # Placeholder text if no image
            self.image_label.configure(image="", 
                text=f"Title Screen\n\nTraveling Through Early American History\n\n(Add title_screen.webp to assets folder)")
        
        # Create centered play button with better layout
        # Clear the grid configuration first
        self.buttons_frame.grid_columnconfigure(0, weight=1)
        self.buttons_frame.grid_columnconfigure(1, weight=1)
        
        # Create play button spanning both columns for centering
        play_btn = ttk.Button(self.buttons_frame, 
                             text="▶ PLAY GAME", 
                             style='Play.TButton',
                             command=self.start_game)
        play_btn.grid(row=0, column=0, columnspan=2, pady=20, padx=200, sticky=(tk.W, tk.E))
        
        # Optional: Add quit button on title screen, also centered
        quit_btn = ttk.Button(self.buttons_frame, 
                             text="Quit",
                             command=self.quit_game)
        quit_btn.grid(row=1, column=0, columnspan=2, pady=5, padx=300, sticky=(tk.W, tk.E))
        
        # Clear status
        self.status_var.set("Press Play to begin your journey... (Press ESC or F11 to toggle fullscreen)")
    
    def start_game(self):
        """Start the game from title screen"""
        # Show text display again
        self.text_display.grid()
        
        # Mark game as started
        self.game_started = True
        
        # Load first scene
        self.load_scene("start")
    
    def load_image(self, image_path):
        """Load and display an image"""
        try:
            # Use resource_path to get correct path for both dev and executable
            full_path = resource_path(image_path)
            
            if os.path.exists(full_path):
                # Open and resize image
                image = Image.open(full_path)
                # Resize to fit nicely in window (max 400x300)
                image.thumbnail((400, 300), Image.Resampling.LANCZOS)
                
                # Convert to PhotoImage
                self.current_image = ImageTk.PhotoImage(image)
                self.image_label.configure(image=self.current_image, text="")
            else:
                # Show placeholder if image not found
                self.image_label.configure(image="", text=f"Image not found: {image_path}")
        except Exception as e:
            self.image_label.configure(image="", text=f"Error loading image: {str(e)}")
    
    def display_text(self, text):
        """Display text in the text widget"""
        self.text_display.configure(state=tk.NORMAL)
        self.text_display.delete(1.0, tk.END)
        self.text_display.insert(1.0, text)
        self.text_display.configure(state=tk.DISABLED)
    
    def create_choice_buttons(self, choices):
        """Create buttons for player choices"""
        # Clear existing buttons
        for widget in self.buttons_frame.winfo_children():
            widget.destroy()
        
        # Create new buttons
        for i, (choice_text, next_scene) in enumerate(choices):
            btn = ttk.Button(self.buttons_frame, text=choice_text,
                           command=lambda scene=next_scene, choice=choice_text: self.make_choice(scene, choice))
            btn.grid(row=i//2, column=i%2, padx=5, pady=5, sticky=(tk.W, tk.E))
        
        # Configure column weights for even distribution
        self.buttons_frame.grid_columnconfigure(0, weight=1)
        self.buttons_frame.grid_columnconfigure(1, weight=1)
    
    def make_choice(self, next_scene, choice_text):
        """Handle player choice"""
        # Check for special commands
        if next_scene == "QUIT_GAME":
            self.quit_game()
            return
        
        if next_scene == "RESTART":
            self.restart_game()
            return
        
        # Record the choice
        self.choices_made[self.current_scene] = choice_text
        
        # Update status
        self.status_var.set(f"You chose: {choice_text}")
        
        # Load next scene
        self.load_scene(next_scene)
    
    def quit_game(self):
        """Quit the game with confirmation"""
        if messagebox.askyesno("Quit Game", "Are you sure you want to quit the game?"):
            self.root.quit()
            self.root.destroy()
    
    def load_scene(self, scene_id):
        """Load a specific scene"""
        scene = self.game_data.get_scene(scene_id)
        
        if not scene:
            messagebox.showerror("Error", f"Scene '{scene_id}' not found!")
            return
        
        self.current_scene = scene_id
        
        # Update title if scene has one
        if 'title' in scene:
            self.title_label.configure(text=scene['title'])
        
        # Load image
        if 'image' in scene:
            image_path = os.path.join('assets', scene['image'])
            self.load_image(image_path)
        
        # Display text
        self.display_text(scene['text'])
        
        # Create choice buttons
        if 'choices' in scene:
            self.create_choice_buttons(scene['choices'])
        else:
            # No choices - this might be an ending
            self.create_ending_buttons()
    
    def create_ending_buttons(self):
        """Create buttons for game ending"""
        for widget in self.buttons_frame.winfo_children():
            widget.destroy()
        
        restart_btn = ttk.Button(self.buttons_frame, text="Start Over",
                               command=self.restart_game)
        quit_btn = ttk.Button(self.buttons_frame, text="Quit",
                            command=self.quit_game)
        
        restart_btn.grid(row=0, column=0, padx=5, pady=5)
        quit_btn.grid(row=0, column=1, padx=5, pady=5)
    
    def restart_game(self):
        """Restart the game"""
        self.current_scene = "start"
        self.inventory = []
        self.choices_made = {}
        self.status_var.set("")
        self.game_started = False
        self.show_title_screen()
    
    def toggle_fullscreen(self, event=None):
        """Toggle fullscreen mode"""
        current_state = self.root.attributes('-fullscreen')
        self.root.attributes('-fullscreen', not current_state)
        return 'break'
    
    def run(self):
        """Start the game"""
        self.root.mainloop()

if __name__ == "__main__":
    # Check if assets folder exists (for development mode)
    if not hasattr(sys, '_MEIPASS'):
        # Running in normal Python mode
        if not os.path.exists('assets'):
            os.makedirs('assets')
            print("Created 'assets' folder - please add your images here!")
    
    game = LiteratureAdventure()
    game.run()