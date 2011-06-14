#pragma once

class													SummerfaceList;

class													ListView
{
	public:
		virtual											~ListView						() {}
	
		virtual bool									Input							() {return false;};
		virtual bool									Draw							() {return false;};
};

class													CleanListView : public ListView
{
	public:
														CleanListView					(SummerfaceList_WeakPtr aList); //External
														~CleanListView					() {};
														
		virtual bool									DrawItem						(SummerfaceItem_Ptr aItem, uint32_t aX, uint32_t aY, bool aSelected); //External
														
		virtual bool									Input							(); //External
		virtual bool									Draw							(); //External

	protected:
		SummerfaceList_WeakPtr							WeakList;
};


class													AnchoredListView : public ListView
{
	public:
														AnchoredListView				(SummerfaceList_WeakPtr aList, bool aAnchored = true, bool aWrap = false); //External
														~AnchoredListView				() {};
														
		virtual bool									DrawItem						(SummerfaceItem_Ptr aItem, uint32_t aX, uint32_t aY, bool aSelected); //External
														
		virtual bool									Input							(); //External
		virtual bool									Draw							(); //External

	protected:
		SummerfaceList_WeakPtr							WeakList;
		int32_t											FirstLine;
		uint32_t										LinesDrawn;

		bool											Anchored;
		bool											Wrap;
};

class													GridListView : public ListView
{
	public:
														GridListView					(SummerfaceList_WeakPtr aList, uint32_t aWidth, uint32_t aHeight, bool aHeader = true, bool aLabels = false); //External
		virtual											~GridListView					() {};
		
		virtual bool									DrawItem						(SummerfaceItem_Ptr aItem, uint32_t aX, uint32_t aY, uint32_t aWidth, uint32_t aHeight, bool aSelected); //External
		
		virtual bool									Input							(); //External
		virtual bool									Draw							(); //External
		
	protected:
		SummerfaceList_WeakPtr							WeakList;

		uint32_t										Width;
		uint32_t										Height;
		
		int32_t											FirstItem;

		bool											DrawHeader;
		bool											RefreshHeader;
		bool											DrawLabels;
};

class													SummerfaceList : public SummerfaceWindow
{
	public:
														SummerfaceList					(const Area& aRegion); //External
		virtual											~SummerfaceList					() {};

		virtual bool									Draw							() {return View->Draw();};
		virtual bool									Input							() {return View->Input();};


		uint32_t										GetSelection					() const {return SelectedIndex;};
		void											SetSelection					(uint32_t aIndex); //External
		void											SetSelection					(const std::string& aText); //External

		SummerfaceItem_Ptr								GetSelected						() const {return (SelectedIndex < Items.size()) ? Items[SelectedIndex] : SummerfaceItem_Ptr();};
		SummerfaceItem_Ptr								GetItem							(uint32_t aIndex) {return (aIndex < Items.size()) ? Items[aIndex] : SummerfaceItem_Ptr();};

		virtual void									AddItem							(SummerfaceItem_Ptr aItem); //External
		virtual void									ClearItems						(); //External

		uint32_t										GetItemCount					() const {return Items.size();}
		bool											WasCanceled						() const {return Canceled;};
		void											SetCanceled						(bool aCanceled) {Canceled = aCanceled;};

		void											SetFont							(Font* aFont); //External
		Font*											GetFont							() const {return LabelFont;}

		void											SetView							(ListView_Ptr aView); //External
		ListView_Ptr									GetView							() const {return View;}

		void											Sort							(bool (*aCallback)(SummerfaceItem_Ptr, SummerfaceItem_Ptr) = 0); //External

	private:
		uint32_t										SelectedIndex;
		bool											Canceled;

		Font*											LabelFont;
		
		ListView_Ptr									View;
		std::vector<SummerfaceItem_Ptr>					Items;
};

