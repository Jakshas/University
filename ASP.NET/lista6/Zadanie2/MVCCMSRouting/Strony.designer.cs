﻿#pragma warning disable 1591
//------------------------------------------------------------------------------
// <auto-generated>
//     Ten kod został wygenerowany przez narzędzie.
//     Wersja wykonawcza:4.0.30319.42000
//
//     Zmiany w tym pliku mogą spowodować nieprawidłowe zachowanie i zostaną utracone, jeśli
//     kod zostanie ponownie wygenerowany.
// </auto-generated>
//------------------------------------------------------------------------------

namespace MVCCMSRouting
{
	using System.Data.Linq;
	using System.Data.Linq.Mapping;
	using System.Data;
	using System.Collections.Generic;
	using System.Reflection;
	using System.Linq;
	using System.Linq.Expressions;
	using System.ComponentModel;
	using System;
	
	
	[global::System.Data.Linq.Mapping.DatabaseAttribute(Name="zadanie2l6")]
	public partial class StronyDataContext : System.Data.Linq.DataContext
	{
		
		private static System.Data.Linq.Mapping.MappingSource mappingSource = new AttributeMappingSource();
		
    #region Extensibility Method Definitions
    partial void OnCreated();
    partial void InsertStrony(Strony instance);
    partial void UpdateStrony(Strony instance);
    partial void DeleteStrony(Strony instance);
    #endregion
		
		public StronyDataContext() : 
				base(global::System.Configuration.ConfigurationManager.ConnectionStrings["zadanie2l6ConnectionString"].ConnectionString, mappingSource)
		{
			OnCreated();
		}
		
		public StronyDataContext(string connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public StronyDataContext(System.Data.IDbConnection connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public StronyDataContext(string connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public StronyDataContext(System.Data.IDbConnection connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public System.Data.Linq.Table<Strony> Strony
		{
			get
			{
				return this.GetTable<Strony>();
			}
		}
	}
	
	[global::System.Data.Linq.Mapping.TableAttribute(Name="dbo.Strony")]
	public partial class Strony : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _ID;
		
		private string _Nazwa;
		
		private string _Strona;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIDChanging(int value);
    partial void OnIDChanged();
    partial void OnNazwaChanging(string value);
    partial void OnNazwaChanged();
    partial void OnStronaChanging(string value);
    partial void OnStronaChanged();
    #endregion
		
		public Strony()
		{
			OnCreated();
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_ID", DbType="Int NOT NULL", IsPrimaryKey=true)]
		public int ID
		{
			get
			{
				return this._ID;
			}
			set
			{
				if ((this._ID != value))
				{
					this.OnIDChanging(value);
					this.SendPropertyChanging();
					this._ID = value;
					this.SendPropertyChanged("ID");
					this.OnIDChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Nazwa", DbType="NVarChar(50)")]
		public string Nazwa
		{
			get
			{
				return this._Nazwa;
			}
			set
			{
				if ((this._Nazwa != value))
				{
					this.OnNazwaChanging(value);
					this.SendPropertyChanging();
					this._Nazwa = value;
					this.SendPropertyChanged("Nazwa");
					this.OnNazwaChanged();
				}
			}
		}
		
		[global::System.Data.Linq.Mapping.ColumnAttribute(Storage="_Strona", DbType="NVarChar(MAX)")]
		public string Strona
		{
			get
			{
				return this._Strona;
			}
			set
			{
				if ((this._Strona != value))
				{
					this.OnStronaChanging(value);
					this.SendPropertyChanging();
					this._Strona = value;
					this.SendPropertyChanged("Strona");
					this.OnStronaChanged();
				}
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
}
#pragma warning restore 1591
